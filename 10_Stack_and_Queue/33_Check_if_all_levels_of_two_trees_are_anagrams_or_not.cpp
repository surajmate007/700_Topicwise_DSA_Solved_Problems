// This is the simple solution. We are first finding the level order traversal for both the trees and then sorting each subvector of level order traversal
// and comparing them.

class Solution{
    public:
    
    void levelOrder(Node* root, vector<vector<int>>& a){
        if(root == NULL){
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> vec;
            
            while(n--){
                Node* nd = q.front();
                vec.push_back(nd->data);
                q.pop();
                
                if(nd->left){
                    q.push(nd->left);
                }
                if(nd->right){
                    q.push(nd->right);
                }
            }
            a.push_back(vec);
        }
    }
    
    bool areAnagrams(Node *root1, Node *root2){
        vector<vector<int>> a, b;
        levelOrder(root1, a);
        levelOrder(root2, b);
        int n = a.size();
        
        for(int i=0; i<n; i++){
            vector<int> veca = a[i];
            vector<int> vecb = b[i];
            sort(veca.begin(), veca.end());
            sort(vecb.begin(), vecb.end());
            if(veca != vecb){
                return false;
            }
        }
        
        return true;
    }
};
