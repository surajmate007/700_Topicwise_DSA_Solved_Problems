// This approach is simple weare first storing the inorder of both the trees and then we are merging the inorder of both the trees.
// After merging that we are then forming the BST from the array like the previous preoblem.

// Approach : 1

// step 1: Form inorder of both the trees.
// step 2: Merge inorder of both the trees.
// step 3: Fom BST using the merged array.

void getInorder(TreeNode<int>* root, vector<TreeNode<int>*>& vec){
    if(root == NULL){
        return;
    }
    
    getInorder(root->left, vec);
    vec.push_back(root);
    getInorder(root->right, vec);
}

void merge(vector<TreeNode<int>*> vec1, vector<TreeNode<int>*> vec2, vector<TreeNode<int>*>& ans){
    int i=0; int j=0;
    int n = vec1.size(); int m = vec2.size();
    while(i<n and j<m){
        if(vec1[i]->data < vec2[j]->data){
            ans.push_back(vec1[i]);
            i++;
        }
        else{
            ans.push_back(vec2[j]);
            j++;
        }
    }
    
    while(i<n){
        ans.push_back(vec1[i]);
        i++;
    }
    
    while(j<m){
        ans.push_back(vec2[j]);
        j++;
    }
}

TreeNode<int>* formBST(vector<TreeNode<int>*> ans, int lo, int hi){
    if(lo > hi){
        return NULL;
    }
    
    int mid = (lo+hi)/2;
    TreeNode<int>* nd = ans[mid];
    nd->left = formBST(ans, lo, mid-1);
    nd->right = formBST(ans, mid+1, hi);
    
    return nd;
}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    if(!root1){
        return root2;
    }
    if(!root2){
        return root1;
    }
    vector<TreeNode<int>*> vec1, vec2;
    getInorder(root1, vec1);
    getInorder(root2, vec2);
    
    vector<TreeNode<int>*> ans;
    merge(vec1, vec2, ans);
    
    int n = ans.size();
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]->data<<" ";
    }
    
    return formBST(ans, 0, n-1);
}


// Approach 2:

// step 1: flatten the tree into Linkedlist and form 2 sorted LL.
// step 2: Merge 2 sorted LL.
// step 3: form BST uisng sorted LL.


//*************APPROACH 2***************************
void convertToDoublyLL(TreeNode<int> *root, TreeNode<int>* &head){
    if(root == NULL)
        return;
    
    convertToDoublyLL(root->right, head);
    root->right = head;
    
    if(head != NULL)
        head->left = root;
    
    head = root;
    
    convertToDoublyLL(root->left, head);
}

TreeNode<int>* mergeTwoSortedLL(TreeNode<int> *head1, TreeNode<int> *head2){
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    
    return head;
}

int countNodes(TreeNode<int> *head){
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n){
    if(n<=0 || head == NULL)
    {
        return NULL;
    }
    
    TreeNode<int>* left = sortedLLToBST(head, n/2);
    
    TreeNode<int>* root = head;
    root->left = left;
    
    head = head->right;
    
    root->right = sortedLLToBST(head, n- n/2 - 1);
    
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    //************APPROACH 2**************
    TreeNode<int>* head1 = NULL;
    convertToDoublyLL(root1, head1);
    head1->left = NULL;
    
    TreeNode<int>* head2 = NULL;
    convertToDoublyLL(root2, head2);
    head2->left = NULL;
    
    TreeNode<int> *head = mergeTwoSortedLL(head1, head2);
    
    return sortedLLToBST(head, countNodes(head));
}
