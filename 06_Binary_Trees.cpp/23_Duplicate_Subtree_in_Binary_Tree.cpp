// we are using unordered_map and stroing all the strings that can be made out of the tree traversal

class Solution {
  public:
  
    
    unordered_map<string, int>m;
    
    string formSubtree(Node*root){
       if(root==NULL){
           return "$";
       }
       
       string s="";
       if(root->right==NULL && root->left==NULL){
           s = to_string(root->data);
           return s;
       }
       
       s= s + to_string(root->data);
       s= s + formSubtree(root->left);
       s= s + formSubtree(root->right);
       m[s]++;
       return s;
   }
   
   int dupSub(Node *root) {
        // code here
        formSubtree(root);
        for(auto x : m){
            if(x.second>=2){
                return true;
            }
        }
        return false;
   }
};


// leetcode problem similar to this only some modification in string formation.

class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string, pair<TreeNode*, bool>> mp;
    
    string getStr(TreeNode* root){
        string s = "";
        if(root == NULL){
            return "$";
        }
        
        s += ("_" + to_string(root->val));
        s += ("_" + getStr(root->left));
        s += ("_" + getStr(root->right));
        
        if(mp.find(s) != mp.end() and mp[s].second == false){
            ans.push_back(mp[s].first);
            mp[s].second = true;
        }
        
        mp[s] = {root, mp[s].second};
        
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == NULL){
            return ans;
        }
        
        getStr(root);
        for(auto e : mp){
            cout<<e.first<<" "<<e.second.first->val<<" "<<e.second.second<<endl;
        }
        return ans;
    }
};
