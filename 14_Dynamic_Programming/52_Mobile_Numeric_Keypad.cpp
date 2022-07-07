// brute force approach where we are using depth first search.
// this solution is giving TLE for larger testcases.

class Solution{
	public:
	unordered_map<int, pair<int, vector<int>>> mp;
	
	long long getAns(int n){
	    queue<int> q;
	    for(int i=0; i<10; i++){
	        q.push(i);
	    }
	    
	    long long last = 0;
	    long long ans = 0;
	    
	    while(!q.empty()){
	        
	        int sz = q.size();
	        n--;
	        
	        if(n==0){
	            return ans-last;
	        }
	        
	        last = ans;
	        
	        while(sz--){
	            int s = q.front(); q.pop();
	            ans += mp[s].first;
	            for(auto e : mp[s].second){
	                q.push(e);
	            }
	        }
	    }
	    
	    return -1;
	}
	
	long long getCount(int n){
	    mp.clear();
		mp[1] = {3, {1,2,4}};
	    mp[2] = {4, {2, 1, 3, 5}};
	    mp[3] = {3, {3, 2, 6}};
	    mp[4] = {4, {4, 1, 5, 7}};
	    mp[5] = {5, {5, 2, 4, 8, 6}};
	    mp[6] = {4, {6, 3, 5, 9}};
	    mp[7] = {3, {7, 4, 8}};
	    mp[8] = {5, {8, 7, 5, 9, 0}};
	    mp[9] = {3, {9, 6, 8}};
	    mp[0] = {2, {0, 8}};
	    
	    if(n==1){
	        return 10;
	    }
	    
	    return getAns(n);
	}
};


// Recursive solution using dfs:
// using dp with dfs.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<vector<long long>> dp;
	vector<vector<int>> dir = {{0,0}, {0,1}, {1,0}, {0,-1}, {-1,0}};
	
	long long getAns(vector<vector<int>>& a, int i, int j, int n){
	    if(n==0){
	        return 0;
	    }
	    int val = a[i][j]-'0';
	    
	    if(dp[val][n] != -1){
	        return dp[val][n];
	    }
	    
	    long long ans = 0;
	    
	    for(auto d : dir){
	        int x = i+d[0]; int y = j+d[1];
	        
	        if(x<=3 and y<=2 and x>=0 and y>=0 and a[x][y] != '*' and a[x][y] != '#'){
	            ans += getAns(a, x, y, n-1);
	        }
	    }
	    
	    return dp[val][n] = ans;
	}
	
	long long getCount(int n){
	     vector<vector<int>> a = {{'1', '2' ,'3'},
	                              {'4', '5', '6'},
	                              {'7', '8', '9'},
	                              {'#', '0', '*'}};
	                              
	     
	     dp.resize(10, vector<long long>(n+1, -1));
	     
	     for(int i=0; i<10; i++){
             dp[i][0] = 0;
         }
         
	     for(int i=0; i<10; i++){
	         dp[i][1] = 1;
	     }
         long long ans = 0;
         
         for(int i=0; i<4; i++){
             for(int j=0; j<3; j++){
                 if(a[i][j] != '#' and a[i][j] != '*'){
                     ans += getAns(a, i, j, n);
                 }
             }
         }
         
         return ans;
	 }
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends

