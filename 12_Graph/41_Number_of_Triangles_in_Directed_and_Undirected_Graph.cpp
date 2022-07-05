// here type=1 meand undirected graph and type = 0 means directed graph.
// We are considering any 3 vertices in the graph and checking whether the edge exists in between in these 3 vertices.
// if the edge exists means it can form a triangle.
// for undirected graph for single triangle cnt value will be 6 and for directed graph the cnt value will be 3.
// hence we will divide by 6 and 3 respetively.

#define N 100;
int solve(int graph[][N], int type){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(graph[i][j] and graph[j][k] and graph[i][k]){
                    cnt++;
                }
            }
        }
    }
    
    if(type == 1){
        cnt /= 6;
    }
    else{
        cnt /= 3;
    }
    
    return cnt;
}
