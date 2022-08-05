// This is the KMP algorithm preprocessing part called as longest prefix suffix:

class Solution{
  public:		
	int lps(string s) {
	    int n = s.length(); 
	    vector<int> lps(s.size(), 0);
	    int i=1; int j=0;
	    while(i < n){
	        if(s[i] == s[j]){
	            lps[i] = j+1;
	            i++; j++;
	        }
	        else{
	            if(j==0){
	                lps[i] = 0;
	                i++;
	            }
	            else{
	                j = lps[j-1];
	            }
	        }
	    }
	    return lps[n-1];
	}
};


// Complete KMP algorithm is explained below:

void computeLPSArray(char* pat, int M, int* lps);
  
// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
  
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
  
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
  
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
  
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
  
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
  
    lps[0] = 0; // lps[0] is always 0
  
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
  
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
  

// Implemented KMP:


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void getLps(string p, int n, vector<int>& lps){
    int i=1; int j=0;
    
    while(i<n){
        if(p[i] == p[j]){
            lps[i] = j+1;
            i++; j++;
        }
        else{
            if(j==0){
                lps[i] = 0; i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
}

int getAns(string& s, string& p){
    int n = s.length(); int m = p.length();
    vector<int> lps(m, 0);
    getLps(p, m, lps);
    int ans = 0;
    
    int i=0; int j=0;
    while(i<n){
        if(s[i] == p[j]){
            i++; j++;
        }
        
        if(j==m){
            ans++;
            j = lps[j-1];
        }
        
        else if(i<n and p[j] != s[i]){
            if(j==0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    
    return ans;
}

int main() {
    int t; cin>>t;
    while(t--){
        string p, s;
        cin>>p>>s;
        
        int ans = getAns(s, p);
        cout<<ans<<endl;
    }
    return 0;
}
