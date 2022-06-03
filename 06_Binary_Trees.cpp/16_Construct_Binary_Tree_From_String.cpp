// In this we are simply creating the stack and only storing the nodes into the satck.
// When we encounter ')' we pop the element from the stack.

// code written by me.
/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}


Node* str2tree(string s) {
        int n = s.length();
        stack<Node*> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == ')'){
                st.pop();
            }
            else if(ch != ')' and ch != '('){
                Node* nd = newNode(ch-'0');
                nd->left = NULL; nd->right = NULL;

                if(!st.empty()){
                    Node* temp = st.top();
                    if(temp->left){
                        temp->right = nd;
                    }
                    else{
                        temp->left = nd;
                    }
                }

                st.push(nd);
            }
        }
        return st.top();
    }
