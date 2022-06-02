// same approach of top view just keep on updating the map until last entry.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        map<int, int> mp;
        
        while(!q.empty()){
            auto ele = q.front();
            Node* nd = ele.first;
            int dist = ele.second;
            
            mp[dist] = nd->data;
            
            if(nd->left){
                q.push({nd->left, dist-1});
            }
            
            if(nd->right){
                q.push({nd->right, dist+1});
            }
            
            q.pop();
        }
        
        for(auto ele : mp){
            ans.push_back(ele.second);
        }
        
        return ans;
    }
};
