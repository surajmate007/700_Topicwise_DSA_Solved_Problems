// Here the approach is simple:
// 1. we will first compute the length of max palindromic substring starting from 0th index.
// 2. Then return all the remaining characters which are not part of this substring.

// O(n) Approach:
// Today I understood the use of longest prefx and suffix (lps):

class Solution {
public:

    void findLPS(string str, int n, vector<int>& lps){
        int i=1; int j=0;
        
        while(i<n){
            if(str[i] == str[j]){
                lps[i] = j+1;
                i++; j++;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }
    }

    int minChar(string s){
        int n = s.length();
        string p = s;
        reverse(p.begin(), p.end());
        string str = s + '&' + p;
        int len = str.length();
        vector<int> lps(len, 0);
        findLPS(str, len, lps);
        return n - lps.back();
    }
};





// TC : O(n^2)
bool isPalin(string s){
        int i=0; int j=s.length()-1;
        while(i<j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int minChar(string s){
        int i=0; int n = s.length();
        int count = 0;
        while(i < n){
            if(isPalin(s.substr(0, i+1))){
                count = max(count, i+1);
            }
            i++;
        }
        
        return n - count;
        
}
