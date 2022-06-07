// This is the simple and intuitive code using unordered_map.

class Solution{
public:
    
    void fillmap(Node* root, unordered_map<int, int>& mp){
        if(root == NULL){
            return;
        }
        
        fillmap(root->left, mp);
        
        mp[root->data]++;
        
        fillmap(root->right, mp);
    }
    
    
    int countPairs(Node* root1, Node* root2, int x){
        unordered_map<int, int> mp1, mp2;
        
        fillmap(root1, mp1);
        fillmap(root2, mp2);
        
        int ans = 0;
        
        for(auto it : mp1){
            int val = x-(it.first);
            if(mp2.find(val) != mp2.end()){
                ans += mp2[val];
            }
        }
        return ans;
    }
};



// Without using extra space.
// Just fix the element in one tree and find the remaining value in the other tree.
// TC = O(n * h), where n is the number of nodes in one tree and h is the height of another tree.


class Solution{
public:
    
    int ans = 0;
    
    void find(Node* root, int val){
        if(root == NULL){
            return;
        }
        
        if(root->data == val){
            ans++;
            return;
        }
        
        if(root->data > val){
            return find(root->left, val);
        }
        
        if(root->data < val){
            return find(root->right, val);
        }
    }
    
    
    void inorder(Node* root1, Node* root2, int x){
        if(root1 == NULL){
            return;
        }
        
        inorder(root1->left, root2, x);
        
        find(root2, (x-root1->data));
        
        inorder(root1->right, root2, x);
    }
    

    int countPairs(Node* root1, Node* root2, int x){
        ans = 0;
        inorder(root1, root2, x);
        return ans;
    }
};


