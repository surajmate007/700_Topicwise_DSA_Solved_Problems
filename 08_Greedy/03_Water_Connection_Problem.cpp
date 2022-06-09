// This is very good approach without using any graph data structure.

vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector <vector<int>> ans;
        vector <int> v(n+1,0);
        map <int, vector <int>> m;
        for(int i =0;i<p;i++){
            m[a[i]].push_back(b[i]);
            m[a[i]].push_back(d[i]);
            v[a[i]]++;
            v[b[i]]++;
        }
        for(int i =1;i<n+1;i++){
            int min1 = INT_MAX;
            if(v[i]==1){
                int a = i;
                if(m[a].size()==0){
                    continue;
                }
                else{
                    vector <int> temp;
                    temp.push_back(a);
                    while(m[a].size()!=0){
                        min1 = min(min1,m[a][1]);    
                        a= m[a][0];
                    }
                    temp.push_back(a);
                    temp.push_back(min1);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
