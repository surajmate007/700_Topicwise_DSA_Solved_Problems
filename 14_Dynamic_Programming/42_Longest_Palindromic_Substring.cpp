

int longestPalSubstr(string str){
    // get length of input string
    int n = str.size();

    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    // here i represents the start index and j reresents the end index of the string.
    bool table[n][n];

    memset(table, 0, sizeof(table));

    // All substrings of length 1 are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // check for sub-string of length 2.
    
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;

                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    
    
    
class Solution {
    public:
    
    string longestPalindrome(string s) {
        int n = s.length(); int maxlen = 1; int start = 0;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                maxlen = 2; start = i;
            }
        }
        
        for(int k=3; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j = i+k-1;
                if(dp[i+1][j-1] and s[i] == s[j]){
                    dp[i][j] = 1;
                    
                    if(k > maxlen){
                        maxlen = k; start = i;
                    }
                }
            }
        }
        
        string ans = s.substr(start, maxlen);
        return ans;
    }
};
