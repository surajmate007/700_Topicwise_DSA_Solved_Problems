// This is the simple solution approach where we are creating the nodes int the same order of visiting them in BFS fashion.
// For this we are creating 2 queues and then inserting the original; graph node in q1 and copied node in q2 and thus we are forming the connections
// between the adjacent nodes.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        unordered_map<int, Node*> mp;
        queue<Node*> q1;
        queue<Node*> q2;
        
        q1.push(node);
        Node* start = new Node(node->val);
        q2.push(start);
        mp[start->val] = start;
        
        while(!q1.empty()){
            Node* nd1 = q1.front();
            Node* nd2 = q2.front();
            q1.pop(); q2.pop();
            vector<Node*> adj;
            
            for(auto e : nd1->neighbors){
                if(mp.find(e->val)==mp.end()){
                    Node* nnd = new Node(e->val); 
                    mp[nnd->val] = nnd;
                    adj.push_back(nnd);
                    q1.push(e);
                    q2.push(nnd);
                }
                else{
                    adj.push_back(mp[e->val]);
                }
            }
            
            nd2->neighbors = adj;
        }
        
        return start;
    }
};
