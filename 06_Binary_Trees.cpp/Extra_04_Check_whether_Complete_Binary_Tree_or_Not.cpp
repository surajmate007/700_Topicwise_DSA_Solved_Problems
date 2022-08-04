// for complete binary tree when we come across first NULL node then we set the flag and after that if we found any node then we will say that
// the tree is not complete.

class Solution{
public:    
    
    bool isCompleteBT(Node* root){
        queue<Node*> q;
        int marked = 0;
        q.push(root);
        
        while(!q.empty()){
            Node* nd = q.front(); q.pop();
                
            if(!nd->left){
                marked = 1;
            }
            else{
                if(marked == 1){
                    return false;
                }
                else{
                    q.push(nd->left);
                }
            }
                
            if(!nd->right){
                marked = 1;
            }
            else{
                if(marked == 1){
                    return false;
                }
                else{
                    q.push(nd->right);
                }
            }            
        }
        
        return true;
    }
};
