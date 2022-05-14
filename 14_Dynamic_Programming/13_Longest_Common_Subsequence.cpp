// simple recursive approach. 
// BASE CONDITION : if length of any of the strings is 0 then return 0
// we will start from last index of both the strings and keep on checking whether the character is same or not. If the character is same then then
// we will reduce index over both the strings and add 1 to answer. if characters are not same then we will take max of one index reduction of both the strings.

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
        if(x==0 or y==0){
            return 0;
        }
        if(s1[x-1] == s2[y-1]){
            return lcs(x-1, y-1, s1, s2)+1;
        }
        else{
            return max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1, s2));
        }
    }
};

// Memoized approach:

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int dp[1001][1001];
    int lcsdp(int x, int y, string s1, string s2){
        if(x==0 or y==0){
            return 0;
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        else if(s1[x-1] == s2[y-1]){
            return dp[x][y] = 1+lcsdp(x-1, y-1, s1, s2);
        }
        else{
            return dp[x][y] = max(lcsdp(x-1, y, s1, s2), lcsdp(x, y-1, s1, s2));
        }
    }
    
    int lcs(int x, int y, string s1, string s2){
        memset(dp, -1, sizeof(dp));
        return lcsdp(x, y, s1, s2);
    }
};


// top-down approach:
// I am finding top-down approach of every problem so simple.
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
        int dp[x+1][y+1];
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
};
