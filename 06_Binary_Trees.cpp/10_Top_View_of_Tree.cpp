// we are using queue and map for finding the top view.
// Better explained in striver video : https://www.youtube.com/watch?v=Et9OCDNvJ78

class Solution{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        map<int, int>mp;
        
        while(!q.empty()){
            auto ele = q.front();
            Node* nd = ele.first;
            
            if(mp.find(ele.second) == mp.end()){
                mp[ele.second] = ele.first->data;
            }
            
            if(nd->left){
                q.push({nd->left, ele.second-1});
            }
            
            if(nd->right){
                q.push({nd->right, ele.second+1});
            }
            
            q.pop();
        }
        
        for(auto ele : mp){
            ans.push_back(ele.second);
        }
        
        return ans;
    }

};
