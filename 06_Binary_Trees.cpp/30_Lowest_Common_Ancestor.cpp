class Solution{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* ans = NULL;
    
    int findlca(Node* root, int n1, int n2){
        if(root == NULL){
            return -1;
        }
        
        int l = findlca(root->left, n1, n2);
        
        int r = findlca(root->right, n1, n2);
        
        if(l==n1 and r==n2 or l==n2 and r==n1){
            ans = root;
            return root->data;
        }
        
        if(l==n1 and root->data==n2 or l==n2 and root->data==n1){
            ans = root;
            return root->data;
        }
        
        if(r==n1 and root->data==n2 or r==n2 and root->data==n1){
            ans = root;
            return root->data;
        }
        
        if(l==n1 or l==n2){
            return l;
        }
        
        if(r==n1 or r==n2){
            return r;
        }
        
        return root->data;
    }
    
    
    Node* lca(Node* root ,int n1 ,int n2 ){
        findlca(root, n1, n2);
        return ans;
    }
};





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    finding in single traversal (assuming that keys are present)
    TC: O(N)
    SC: O(1)
*/
// This function returns pointer to LCA of two given values n1 and n2.
// This function assumes that n1 and n2 are present in Binary Tree
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;

    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;

    // Look for keys in left and right subtrees
    Node* left_lca = findLCA(root->left, n1, n2);
    Node* right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}
