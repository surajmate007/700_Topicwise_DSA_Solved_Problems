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


class Solution {
public:
    unordered_map<int, int> mp;
    int idx = 0;
    
    TreeNode* helper(vector<int> in, int i, int j){
        if(i>j){
            return NULL;
        }
        
        TreeNode* temp;
        for(int k=i; k<=j; k++){
            if(mp[in[k]] == idx){
                temp = new TreeNode(in[k]);
                idx++;
                temp->left = helper(in, i, k-1);
                temp->right = helper(in, k+1, j);
            }
        }
        
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size();
        vector<int> in = pre;
        sort(in.begin(), in.end());
        for(int i=0; i<n; i++){
            mp[pre[i]] = i;
        }
        
        return helper(in, 0, n-1);
    }
};



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
