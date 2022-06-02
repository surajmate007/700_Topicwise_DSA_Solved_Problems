// using level order traversal approach.
// We are storing only first node in each level.

vector<int> leftView(Node *root){
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       ans.push_back(q.front()->data);
       int n = q.size();
       while(n){
           Node* top = q.front();
           if(top->left){
               q.push(top->left);
           }
           if(top->right){
               q.push(top->right);
           }
           q.pop();
           n--;
       }
   }
   return ans;
}



// More optimised code using preorder traversal.


void getAns(Node* root, int level, vector<int>& ans){
    if(root == NULL){
        return;
    }
    
    if(level == ans.size()){            // we are checking is this the first element from this level by comparing it with size of data structure.
        ans.push_back(root->data);
    }
    
    getAns(root->left, level+1, ans);   // we are going to left child and incrementing the level.
    getAns(root->right, level+1, ans);  // we are going to right child and incrementing the level.
}

vector<int> leftView(Node *root){
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   
   getAns(root, 0, ans);
   
   return ans;
}
