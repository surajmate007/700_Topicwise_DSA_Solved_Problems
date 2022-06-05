// similar problem is also solved on leetcode.


unordered_map<string, int>m;
vector <Node*> v;
string solve(Node*root)
{
   if(!root) return " ";
   string s = " ";

   if(!root->left and !root->right)
   {
       s = to_string(root->data);
       m[s]++;
       
   }
   
   s = s + to_string(root->data);
   s = s + solve(root->left);
   s = s + solve(root->right);
   
    if (m[s] == 1)
        v.push_back (root);
   
       
   m[s]++;
   return s;
   
}

vector<Node*> printAllDups(Node* root){
   // Code here
   m.clear();
   v.clear();
   solve(root);
   return v;
}
