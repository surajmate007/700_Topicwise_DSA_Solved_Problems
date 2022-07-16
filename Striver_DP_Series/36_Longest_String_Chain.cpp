// Tabulation approach exactly same as LIS:


class Solution {
public:
    
    static bool comp(pair<string, int>& a, pair<string, int>& b){
        return a.second < b.second;
    }
    
    bool checker(string a, string b, int n){
        int i=0; int j=0; int k=1;
        while(i<n and j<=n){
            if(a[i] == b[j]){
                i++; j++;
            }
            else{
                k--; j++;
            }
            if(k==-1){
                return false;
            }
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        int ans = 1;

        vector<pair<string, int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({words[i], words[i].length()});
        }
        sort(vec.begin(), vec.end(), comp);
        
        int dp[n];
        for(int i=0; i<n; i++){
            dp[i] = 1;
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(vec[j].second + 1 == vec[i].second and dp[i] < dp[j]+1){
                    if(checker(vec[j].first, vec[i].first, vec[j].second)){
                        dp[i] = max(dp[i], dp[j]+1);
                        ans = max(ans,dp[i]);
                    }
                }
            }
        }
        
        return ans;
    }
};
