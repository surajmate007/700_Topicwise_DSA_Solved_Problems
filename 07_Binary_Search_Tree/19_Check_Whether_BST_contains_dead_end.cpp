// Esay and intuitive approach.

bool check(Node* root, int min, int max){
    if(!root){
        return 1;
    }
    if(root->data == 1 && root->data == max-1){
        return false;
    }
    if(root->data==min+1 && root->data == max-1 ){
        return false;
    }
    return check(root->left, min , root->data) && check(root->right,root->data, max);
}


bool isDeadEnd(Node *root)
{
    //Your code here
    return !check(root, 1 ,INT_MAX);
}
