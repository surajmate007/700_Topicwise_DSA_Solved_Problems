// This is simple solution based on Bellman ford algorithm.
// in Bellman Ford algorithm we run the loop for n-1 times and in such n-1 times all the weights gets setteled to their actual values 
// But when we run the loop for one extra time then if the weights are again getting reduced then there is negativ cycle in the graph.

class Solution {
    
    struct Node{
        int a; int b; int weight;
        
        Node(int s, int d, int val){
            a = s;
            b = d;
            weight = val;
        }
    };
    
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int inf = 1e9+7;
	    
	    vector<Node*> vec;
	    for(int i=0; i<edges.size(); i++){
	        Node* nd = new Node(edges[i][0], edges[i][1], edges[i][2]);
	        vec.push_back(nd);
	    }
	    
	    vector<int> dist(n, inf);
	    dist[0] = 0;
	    
	    for(int i=1; i<=n-1; i++){
	        for(auto& it : vec){
	            if(dist[it->a] + it->weight < dist[it->b]){
	                dist[it->b] = dist[it->a] + it->weight;
 	            }
	        }
	    }
	    
	    int fl = 0;
	    for(auto it : vec){
	        if(dist[it->a] + it->weight < dist[it->b]){
	            fl = 1;
	            break;
	        }
	    }
	    
	    return fl;
	}
};
