// Here we are trying every colour for every single node and checking whether the colouring is possible or not.
// If not then we are backtracing 
// Vector color store the mapping of colours corresponding to vertices.

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isPossible(int i, int c, bool graph[101][101], vector<int> color){
    for(int k = 0; k<101; k++){
        if(graph[i][k] == 1){
            if(color[k] == c){
                return false;
            }
        }
    }
    return true;
}


bool getAns(bool graph[101][101], int m, int n, vector<int>& color){
    for(int i=0; i<n; i++){
        if(color[i] == 0){
            for(int c=1; c<=m; c++){
                if(isPossible(i, c, graph, color)){
                    color[i] = c;
                    
                    if(getAns(graph, m, n, color) == true){
                        return true;
                    }
                    
                    color[i] = 0;
                }
            }
            return false;
        }
    }
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, 0);

    return getAns(graph, m, n, color);
}
