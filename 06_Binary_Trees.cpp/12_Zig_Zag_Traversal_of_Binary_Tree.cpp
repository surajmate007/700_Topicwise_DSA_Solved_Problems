// Not optimised:

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root){
    	vector<int> ans;
    	if(root == NULL){
    	    return ans;
    	}
    	int level = 0;
    	queue<Node*> q;
    	q.push(root);
    	
    	while(!q.empty()){
    	    int n = q.size();
    	    vector<int> vec;
    	    while(n){
    	        Node* nd = q.front();
    	        vec.push_back(nd->data);
    	        
    	        if(nd->left){
    	            q.push(nd->left);
    	        }
    	        
    	        if(nd->right){
    	            q.push(nd->right);
    	        }
    	        
    	        q.pop();
    	        n--;
    	    }
    	    
    	    if(level%2 == 1){
    	        reverse(vec.begin(), vec.end());
    	    }
    	    
    	    for(int e : vec){
    	        ans.push_back(e);
    	    }

    	    level++;
    	}
    	
    	return ans;
    }
};


// Instead of using integer as level we are using boolean to defint the level.
// The boolean will keep on toggeling between true and false.

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root){
    	vector<int> ans;
    	if(root == NULL){
    	    return ans;
    	}
    	bool level = true;
    	queue<Node*> q;
    	q.push(root);
    	
    	while(!q.empty()){
    	    int n = q.size();
    	    vector<int> vec;
    	    while(n){
    	        Node* nd = q.front();
    	        vec.push_back(nd->data);
    	        
    	        if(nd->left){
    	            q.push(nd->left);
    	        }
    	        
    	        if(nd->right){
    	            q.push(nd->right);
    	        }
    	        
    	        q.pop();
    	        n--;
    	    }
    	    
    	    if(level == false){
    	        reverse(vec.begin(), vec.end());
    	    }
    	    
    	    for(int e : vec){
    	        ans.push_back(e);
    	    }

    	    level = !level;
    	}
    	
    	return ans;
    }
};
