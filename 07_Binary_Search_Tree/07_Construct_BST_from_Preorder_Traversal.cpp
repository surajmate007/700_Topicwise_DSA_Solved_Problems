// Code written by me:

// The approach is simple we will first take a stack and keep on pushing these elements which has value less than the top element in the satck.
// Since the element value is less than threw top element of thr stack means that these elements will go to the left of the stack top.
// If the new node value is more than the top of the stack thewnwe will keep on removing the elements form the stack
// until the top has element less than the value of the new node and we will set this new element as the right of the stack top.


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* ans = NULL;
        stack<TreeNode*> st; int n = pre.size();
        TreeNode* nd = new TreeNode(pre[0]);
        ans = nd;
        st.push(nd);
        
        for(int i=1; i<n; i++){
            TreeNode* nd = new TreeNode(pre[i]);
            
            TreeNode* temp = st.top();
            if(pre[i] < temp->val){
                temp = st.top();
                temp->left = nd;
            }
            else{
                while(!st.empty() and pre[i] > st.top()->val){
                    temp = st.top();
                    st.pop();
                }
                temp->right = nd;
            }
            st.push(nd);
        }

        return ans;
    }
};


// Another good approach for this problem is we can sort the preorder then we will get inorder because inordre of BST is always sorted.
// Then from the previous problem solved in Binary trees section we can create the tress from both of these traversals.


TreeNode<int>* formTree(vector<int>& arr, int lo, int hi){
    if(lo > hi){
        return NULL;
    }
    
    int mid = lo + (hi-lo)/2;
    TreeNode<int>* nd = new TreeNode<int> (arr[mid]);
    nd->left = formTree(arr, lo, mid-1);
    nd->right = formTree(arr, mid+1, hi);
    
    return nd;
}

TreeNode<int>* preOrderTree(vector<int> &pre){
    sort(pre.begin(), pre.end());
    int n = pre.size();
    return formTree(pre, 0, n-1);
}



// Final solution in O(n):
// keeping track of upper bound at each position.

class Solution {
public:
    
    TreeNode* build(vector<int> pre, int& i, int bound){
        if(i == pre.size() or pre[i] > bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = build(pre, i, root->val);
        root->right = build(pre, i, bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i=0;
        return build(pre, i, INT_MAX);
    }
};


// Similar way of constructing BST from inorder:


TreeNode<int>* formBST(vector<TreeNode<int>*> ans, int lo, int hi){
    if(lo < hi){
        return NULL;
    }
    
    int mid = (lo+hi)/2;
    TreeNode<int>* nd = ans[mid];
    nd->left = formBST(ans, lo, mid-1);
    nd->right = formBST(ans, mid+1, hi);
    
    return nd;
}
