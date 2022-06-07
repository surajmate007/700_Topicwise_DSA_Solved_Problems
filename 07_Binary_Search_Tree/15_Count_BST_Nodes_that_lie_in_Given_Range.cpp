// This is the brute force approach where we are traversing over all the nodes and checking whether that node is lying in the given range or not.

class Solution{
public:
    int cnt = 0; 
    
    void getAns(Node* root, int l , int h){
        if(root == NULL){
            return;
        }
        
        getAns(root->left, l, h);
        if(root->data >= l and root->data <= h){
            cnt++;
        }
        getAns(root->right, l, h);
    }
    
    int getCount(Node *root, int l, int h){
          if(root == NULL){
              return -1;
          }
          
          cnt = 0;
          getAns(root, l, h);
          
          return cnt;
    }
};



// More optimised solution using BST property.


class Solution{
public:
    int cnt = 0; 
    
    int getCount(Node *root, int l, int h){
      
       static int count = 0;
       
       //if root is null return 0(since there are 0 nodes that lies in the given range)
       if(root == NULL){
           return 0;
       }
       
       /*if root lies in the given range we can count this node for our ans and
       make call for both left and right subtree since there can be more elements in the range
       on either side of the root*/
       if(root->data >= l && root->data <= h){
           count = 1 + getCount(root->left,l,root->data)+getCount(root->right,root->data,h);
       }
       
       /*if root->data is less than the lower limit then no need of searching 
       for elements in left subtree anymore */
       if(root->data < l){
           return getCount(root->right,l,h);
       }
       
       /*if root->data is less than the lower limit then no need of searching 
       for elements in left subtree anymore */
       if(root->data > h){
           return getCount(root->left,l,h);
       }
       
       //finally no more recursive calls and we can return our final ans;
       return count;
   }
};
