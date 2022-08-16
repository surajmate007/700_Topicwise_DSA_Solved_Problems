// Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints. 
// Vertex coloring is the most common graph coloring problem. The problem is, given m colors, find a way of coloring the vertices of a graph such that
// no two adjacent vertices are colored using same color. The other graph coloring problems like Edge Coloring (No vertex is incident to two edges of same
// color) and Face Coloring (Geographical Map Coloring) can be transformed into vertex coloring. 
// Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. For example, the following can be colored
// minimum 2 colors. 

// The problem to find chromatic number of a given graph is NP Complete.
// Applications of Graph Coloring:
// The graph coloring problem has huge number of applications. 

// 1) Making Schedule or Time Table: Suppose we want to make am exam schedule for a university. We have list different subjects and students enrolled
// in every subject. Many subjects would have common students (of same batch, some backlog students, etc). How do we schedule the exam so that no two
// exams with a common student are scheduled at same time? How many minimum time slots are needed to schedule all exams? This problem can be represented
// as a graph where every vertex is a subject and an edge between two vertices mean there is a common student. So this is a graph coloring problem where
// minimum number of time slots is equal to the chromatic number of the graph. 

// 2) Mobile Radio Frequency Assignment: When frequencies are assigned to towers, frequencies assigned to all towers at the same location must be different.
// How to assign frequencies with this constraint? What is the minimum number of frequencies needed? This problem is also an instance of graph coloring
// problem where every tower represents a vertex and an edge between two towers represents that they are in range of each other. 

// 3) Sudoku: Sudoku is also a variation of Graph coloring problem where every cell represents a vertex. There is an edge between two vertices if they are
// in same row or same column or same block. 

// 4) Register Allocation: In compiler optimization, register allocation is the process of assigning a large number of target program variables onto a
// small number of CPU registers. This problem is also a graph coloring problem. 

// 5) Bipartite Graphs: We can check if a graph is Bipartite or not by coloring the graph using two colors. If a given graph is 2-colorable, then it is
// Bipartite, otherwise not. See this for more details. 

// 6) Map Coloring: Geographical maps of countries or states where no two adjacent cities cannot be assigned same color. Four colors are sufficient to
// color any map (See Four Color Theorem) 


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
