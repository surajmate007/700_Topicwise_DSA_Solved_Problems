// Recursion:


class Solution{
public:

    int getAns(string& s, int lo, int hi, int want){
        if(lo > hi){
            return 0;
        }
        
        if(lo == hi){
            if(want == 1){
                return s[lo] == 'T';
            }
            else{
                return s[lo] == 'F';
            }
        }
        
        long long ans = 0;
        
        for(int k=lo+1; k<=hi-1; k+=2){
            long long lt = getAns(s, lo, k-1, 1);
            long long lf = getAns(s, lo, k-1, 0);
            long long rt = getAns(s, k+1, hi, 1);
            long long rf = getAns(s, k+1, hi, 0);
            
            if(s[k] == '|'){
                if(want == 1){
                    ans += lt*rf + lf*rt + lt*rt;
                }
                else{
                    ans += lf * rf;
                }
            }
            else if(s[k] == '^'){
                if(want == 1){
                    ans += lt*rf + lf*rt;
                }
                else{
                    ans += lt*rt + lf*rf;
                }
            }
            else{
                if(want == 1){
                    ans += lt * rt;
                }
                else{
                    ans += lt*rf + lf*rt + lf*rf;
                }
            }
        }
        
        return ans;
    }

    int countWays(int N, string S){
        return getAns(S, 0, N-1, 1);
    }
};



// Memoisation:



class Solution{
public:
    int mod = 1003;
    
    int getAns(string& s, int lo, int hi, int want, vector<vector<vector<int>>>& dp){
        if(lo > hi){
            return 0;
        }
        
        if(lo == hi){
            if(want == 1){
                return s[lo] == 'T';
            }
            else{
                return s[lo] == 'F';
            }
        }
        
        if(dp[lo][hi][want] != -1){
            return dp[lo][hi][want]%mod;
        }
        
        long long ans = 0;
        
        for(int k=lo+1; k<=hi-1; k+=2){
            long long lt = getAns(s, lo, k-1, 1, dp)%mod;
            long long lf = getAns(s, lo, k-1, 0, dp)%mod;
            long long rt = getAns(s, k+1, hi, 1, dp)%mod;
            long long rf = getAns(s, k+1, hi, 0, dp)%mod;
            
            if(s[k] == '|'){
                if(want == 1){
                    ans = (ans%mod + (lt*rf)%mod + (lf*rt)%mod + (lt*rt)%mod)%mod;
                }
                else{
                    ans = (ans%mod + (lf*rf)%mod)%mod;
                }
            }
            else if(s[k] == '^'){
                if(want == 1){
                    ans = (ans%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
                }
                else{
                    ans = (ans%mod + (lt*rt)%mod + (lf*rf)%mod)%mod;
                }
            }
            else{
                if(want == 1){
                    ans = (ans%mod + (lt*rt)%mod)%mod;
                }
                else{
                    ans += ((lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;
                }
            }
        }
        
        return dp[lo][hi][want] = ans%mod;
    }

    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (N+1, vector<int> (2, -1)));
        return getAns(S, 0, N-1, 1, dp)%mod;
    }
};
