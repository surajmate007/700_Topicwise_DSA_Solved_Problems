class Solution{
  public:
	
	    struct Node{
	        string symbol;
	        int frequency;
	        Node* left;
	        Node* right;
	        bool isLeaf;
	        
	        Node(string symbol, int frequency){
	            this->symbol = symbol;
	            this->frequency = frequency;
	            this->left = NULL;
	            this->right = NULL;
	            this->isLeaf = false;
	        }
	    };
	    
	    struct CompareNode{
	        bool operator()(Node* a, Node* b){
	            return a->frequency > b->frequency;
	        }
	    };
	    
	    void preOrder(Node* node, string path, vector<string>&result){
	        if(node == NULL){
	            return;
	        }
	        
	        if(node->isLeaf){
	            result.push_back(path);
	        }
	        
	        preOrder(node->left, path+"0", result);
	        preOrder(node->right, path+"1", result);
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, CompareNode> pq;
		    Node *node,*node1,*node2,*newNode,*root;
		    vector<string> result;
		    
		    for(int i=0; i<N; i++){
		        node = new Node(string(1,S[i]),f[i]);
		        node->isLeaf = true;
		        pq.push(node);
		    }
		    
		    while(pq.size() != 1){
		        node1 = pq.top();
		        pq.pop();
		        
		        node2 = pq.top();
		        pq.pop();
		        
		        newNode = new Node((node1->symbol+node2->symbol), (node1->frequency+node2->frequency));
		        newNode->left = node1;
		        newNode->right = node2;
		        pq.push(newNode);
		    }
		    
		    root = pq.top();
		    
		    preOrder(root, "", result);
		    
		    return result;
		}
};
