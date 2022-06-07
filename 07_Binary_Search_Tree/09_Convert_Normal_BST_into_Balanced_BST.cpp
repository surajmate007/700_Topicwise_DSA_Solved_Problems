// Wea are first finding the inorder traversal of the tree and then at every instant we are considering the mid node of the inorder
// traversal as root and keep on forming the new connections with the new upcoming nodes.



void getInorder(Node* root, vector<Node*>& vec){
    if(root == NULL){
        return;
    }
    
    getInorder(root->left, vec);
    vec.push_back(root);
    getInorder(root->right, vec);
}

Node* formTree(vector<Node*> vec, int lo, int hi){
    if(lo > hi){
        return NULL;
    }
    
    int mid = (lo + hi)/2;
    Node* nd = vec[mid];
    nd->left = formTree(vec, lo, mid-1);
    nd->right = formTree(vec, mid+1, hi);
    
    return nd;
}

Node* buildBalancedTree(Node* root){
    if(root == NULL){
        return root;
    }
    
    vector<Node*> vec;
	getInorder(root, vec);
	int n = vec.size();
	
	return formTree(vec, 0, n-1);
}
