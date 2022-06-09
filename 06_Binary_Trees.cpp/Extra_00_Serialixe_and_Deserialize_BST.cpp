// simple approach of finding the string from BST and then converting this string into the BST. from preorder and inorder traversal.

class Codec {
public:
    
    vector<int> in;
    unordered_map<int, int> mp;
    int idx = 0;
    // Encodes a tree to a single string.\
    
    void preorder(TreeNode* root, string& str){
        if(!root){
            return;
        }
        
        str += to_string(root->val);
        str+= "_";
        preorder(root->left, str);
        preorder(root->right, str);
    }
    
    string serialize(TreeNode* root) {
        string str = "";
        preorder(root, str);
        return str;
    }
    
    TreeNode* formTree(int i, int j){
        if(i>j){
            return NULL;
        }
        TreeNode* node;
        for(int k=i; k<=j; k++){
            if(mp[in[k]] == idx){
                node = new TreeNode(in[k]);
                idx = idx+1;
                node->left = formTree(i, k-1);
                node->right = formTree(k+1, j);
            }
        }
        
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        in.clear();
        mp.clear();
        idx = 0;
        int n = 0;
        
        for(int i=0; i<data.length(); i++){
            int s = 0;
            while(data[i] != '_'){
                s = s*10 + (data[i]-'0');
                i++;
            }
            in.push_back(s);
        }
        
        for(int i=0; i<in.size(); i++){
            mp[in[i]] = i;
            n++;
        }
        
        sort(in.begin(), in.end());

        TreeNode* root = formTree(0, n-1);
        
        return root;
    }
};
