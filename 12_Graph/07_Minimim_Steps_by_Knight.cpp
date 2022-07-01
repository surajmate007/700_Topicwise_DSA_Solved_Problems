// using bfs algorithm.

class Solution {
    public:
    
   vector<vector<int>> level;
   vector<vector<bool>> vis;
   
   vector<pair<int,int>> moves={{-2,-1},{-2,1},{2,-1},{2,1},{1,2},{-1,-2},{-1,2},{1,-2}};
   
   bool isvalid(pair<int,int> i , int x , int y , int N){
       return (((x+i.first)>=0 && (x+i.first)<N) && ((y+i.second)>=0 && (y+i.second)<N)) && !vis[x+i.first][y+i.second]; 
   }
   
   
    int minStepToReachTarget(vector<int>&KP,vector<int>&TP,int N){
        level.resize(N, vector<int>(N,0));
        vis.resize(N, vector<bool>(N,false));
        
        queue<pair<int,int>> q;
        q.push({KP[0]-1,KP[1]-1});
        vis[KP[0]-1][KP[1]-1]=true;
        level[KP[0]-1][KP[1]-1]=0;
        
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            
            for(auto i:moves)
            {
                if(isvalid(i,x,y,N))
                {
                    q.push({x+i.first, y+i.second});
                    vis[x+i.first][y+i.second]=true;
                    level[x+i.first][y+i.second]=level[x][y]+1;
                }
            }
        }
        
        return level[TP[0]-1][TP[1]-1];
    }
};
