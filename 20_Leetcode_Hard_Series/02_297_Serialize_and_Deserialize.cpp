/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* nd = q.front(); q.pop();
            if(nd == NULL){
                str += ("?_");
                continue;
            }
            else{
                str += (to_string(nd->val) + '_');
            }

            if(nd->left){
                q.push(nd->left);
            }
            else{
                q.push(NULL);
            }
            if(nd->right){
                q.push(nd->right);
            }
            else{
                q.push(NULL);
            }
        }

        while(!str.empty() and str.back()=='?' or str.back()=='_'){
            str.pop_back();
        }

        return str;
    }

    TreeNode* buildTree(vector<TreeNode*>& arr){
        int n = arr.size(); int idx = 0;
        
        for(int i=0; i<n; i++){
            TreeNode* nd = arr[i];
            if(!nd){
                continue;
            }

            TreeNode* l = NULL;
            TreeNode* r = NULL;
            if(2*idx+1 < n){
                l = arr[2*idx+1];
            }
            if(2*idx+2 < n){
                r = arr[2*idx+2];
            }
            idx++;
            nd->left = l;
            nd->right = r;
        }

        return arr[0];
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> arr;
        int i=0; int n = data.length();
        if(n==0){
            return NULL;
        }

        while(i<n){
            int val = 0; bool neg = false;
            while(i<n and data[i] != '_'){
                if(data[i] == '-'){
                    neg = true;
                    i++;
                    continue;
                }
                else if(data[i] == '?'){
                    arr.push_back(NULL);
                    i+=2;
                    continue;
                }
                val *= 10;
                val += data[i]-'0';
                i++;
            }
            if(neg){
                val *= -1;
            }
            neg = false;
            arr.push_back(new TreeNode(val));
            i++;
        }

        return buildTree(arr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
