// variation of MCM:

class Solution{
public:
    int mod = 1003;
    int solve(string &s, int i, int j, bool isTrue, unordered_map<string,int>&dp){
        if(i > j) return false;
        if(i == j){
            if(isTrue == true) return s[i] == 'T';
            else return s[i] == 'F';
        }
        string temp = to_string(i);
        temp += ' ';
        temp += to_string(j);
        temp += ' ';
        temp += to_string(isTrue);
        if(dp.find(temp) != dp.end()) return dp[temp];
        int ans = 0;
        for(int k=i+1; k<=j-1; k+=2){
            int lt = solve(s,i,k-1,true,dp);
            int lf = solve(s,i,k-1,false,dp);
            int rt = solve(s,k+1,j,true,dp);
            int rf = solve(s,k+1,j,false,dp);
            if(s[k] == '|'){
                if(isTrue) ans += (lt*rt + lt*rf + lf*rt)%mod;
                else ans += (lf*rf)%mod;
            }
            else if(s[k] == '&'){
                if(isTrue) ans += (lt*rt)%mod;
                else ans += (lt*rf + lf*rt + lf*rf)%mod;
            }
            else if(s[k] == '^'){
                if(isTrue) ans += (lt*rf + lf*rt)%mod;
                else ans += (lf*rf + lt*rt)%mod;
            }
        }
        return dp[temp] = ans%mod;
    }
    
    int countWays(int N, string S){
        unordered_map<string,int>dp;
        return solve(S,0,N-1,true,dp);
    }
};
