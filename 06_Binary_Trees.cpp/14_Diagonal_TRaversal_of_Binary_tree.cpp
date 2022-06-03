// we are simply using queue and using same concept as level order traversal.

vector<int> diagonal(Node *root){
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   
   queue<Node*> q;
   
   Node* temp = root;
   while(temp){
       q.push(temp);
       temp = temp->right;
   }
   
   while(!q.empty()){
       Node* nd = q.front();
       Node* left = nd->left;
       
       while(left){
           q.push(left);
           left = left->right;
       }
       
       ans.push_back(nd->data);
       q.pop();
       
   }

   return ans;
}


// better approach using same logic:

vector<int> diagonal(Node *root){
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       while(temp){
           ans.push_back(temp->data);
           if(temp->left){
               q.push(temp->left);
           }
           temp = temp->right;
       }
   }
   
   return ans;
}
