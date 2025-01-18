// Modification od dijkstra using 0-1 DFS

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        deque<pair<int, int>> dq;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> cost(n, vector<int>(m, 1e6));
        dq.push_front({0, 0});
        cost[0][0] = 0;

        while(!dq.empty()){
            pair<int, int> pr = dq.front(); dq.pop_front(); 
            int i = pr.first; int j = pr.second;

            for(int dir = 0; dir<4; dir++){
                int ni = i+dirs[dir].first; int nj = j+dirs[dir].second;
                int ncost = cost[i][j] + (dir != grid[i][j]-1);

                if(ni>=0 and ni<n and nj>=0 and nj<m and cost[ni][nj] > ncost){
                    cost[ni][nj] = ncost;
                    (dir != grid[i][j]-1) ? dq.push_back({ni, nj}) : dq.push_front({ni, nj});
                }
            }
        }

        return cost[n-1][m-1];
    }
};
