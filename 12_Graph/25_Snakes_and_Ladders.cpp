// This solution is written by me but giving error.

class Solution {
public:
    
    pair<int, int> getCordinates(int a, int n){
        int x = (a-1)/n;
        x = n - x - 1; 
        int y = (a-1)%n;
        if(x%2 == 0){
            y = n - y - 1;
        }
        return {x, y};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int vis[n][n];
        memset(vis, 0, sizeof(vis));
        int steps = 0;
        
        queue<int> q;
        q.push(1); vis[n-1][0] = 1;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int a = q.front(); q.pop();
                
                if(a == n*n){
                    return steps;
                }
                
                for(int i=1; i<=6; i++){
                    
                    if(a+i > n*n){
                        break;
                    }
                    
                    pair<int, int> p = getCordinates(a+i, n);
                    int x = p.first; int y = p.second;

                    if(vis[x][y] == 0){
                        vis[x][y] = 1;

                        if(board[x][y]==-1){
                            q.push(a+i);
                        }

                        else{
                            q.push(board[x][y]);
                        }
                    }
                }
            }
            
            steps++;
        }
        return -1;
    }
};

// same bfs solution giving correct result.

class Solution {
    public:
    vector<int> findCoordinates(int n,int position){ 
        vector<int> ans(2);
        int r= n-(position-1)/n-1;
        int c=(position-1)%n;
        if(r%2==n%2) {
            c=n-c-1; 
        }
        ans[0]=r;
        ans[1]=c;
        return ans;
    }


    int snakesAndLadders(vector<vector<int> >& board) {
        int n=board.size();
        vector<vector<bool> > visited(n,vector<bool>(n,false));
        queue<pair<int,int> > q;
        q.push(make_pair(1,0));
        visited[n-1][0]=true;
    
        while(!q.empty()) {
			int currPos=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(currPos==n*n) {
                return steps;
            }

            for(int i=1;i<=6;i++) {
                int nextPos=currPos+i;
                if(nextPos>n*n) break;
                vector<int> temp= findCoordinates(n,nextPos);
                int r=temp[0];
                int c=temp[1];
                if(!visited[r][c]) {
                    visited[r][c]=true;
                    if(board[r][c]!=-1) {
                        q.push(make_pair(board[r][c],steps+1));
                    }
                    else {
                        q.push(make_pair(nextPos,steps+1));
                    }
                }

            }
        }
        return -1;
	}

};
