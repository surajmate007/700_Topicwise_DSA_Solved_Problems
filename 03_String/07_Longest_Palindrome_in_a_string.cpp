// Brute force approach:   O(n^3)
int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();
 
    // All substrings of length 1
    // are palindromes
    int maxLength = 1, start = 0;
 
    // Nested loop to mark start and end index
    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            int flag = 1;
 
            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;
 
            // Palindrome
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }
 
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
 
    // return length of LPS
    return maxLength;
}


// This is the easiest aproach for this problem:
// in this approach we are using 2 loops and considering the substrings in between the 2 pointers declared by 2 loops.

bool isPalin(string s){
      int i=0; int j=s.length()-1;
      while(i< j){
          if(s[i] == s[j]){
              i++; j--;
          }
          else{
              return false;
          }
      }
      return true;
  }
  
    string longestPalin (string s) {
        if(s.length() == 1){
            return s;
        }
        int n = s.length();
        int len = INT_MIN; string ans = "";
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalin(s.substr(i, j-i+1))){    // j-i+1 reprersents the length of the substr.
                    if(j-i+1 > len){
                        len = j-i+1;
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        
        return ans;
}


// In this approach we are using one loop and considering that index as a centre of our longest palindromic substring we are growing our substr in both
// directions and finding the max length possible for the palindromic substr.

void helper(string s, int n, int lo, int hi, int& maxlen, int& start){
        while(lo >= 0 and hi < n){
            if(s[lo] == s[hi]){
                if(hi-lo+1 > maxlen){
                    maxlen = hi-lo+1;
                    start = lo;
                }
                lo--; hi++;
            }
            else{
                break;
            }
        }
    }
  
string longestPalin (string s) {
        if(s.length() == 1){
            return s;
        }
        int n = s.length();
        int maxlen = 1; string ans = ""; int lo, hi; int start = 0;
        for(int i=0; i<n; i++){
            lo = i-1; hi = i+1;
            helper(s, n, lo, hi, maxlen, start);
            lo = i; hi = i+1;
            helper(s, n, lo, hi, maxlen, start);
        }
        
        ans = s.substr(start, maxlen);
        return ans;
}

// This approach is using DP : I tried DP approach first but it is not working.


void printSubStr(
    string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
 
// This function prints the
// longest palindrome substring
// It also returns the length of
// the longest palindrome
int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();
 
    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];
 
    memset(table, 0, sizeof(table));
 
    // All substrings of length 1
    // are palindromes
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
 
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
 
    // return length of LPS
    return maxLength;
}
