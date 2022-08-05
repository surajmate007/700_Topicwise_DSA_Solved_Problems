// This solution approach is provided by gfg:

// d is the number of characters in the input alphabet
#define d 256
 
void search(char pat[], char txt[], int q){
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++){
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if( p == t ){  
            bool flag = true;
            /* Check for characters one by one */
            for (j = 0; j < M; j++){
                if (txt[i+j] != pat[j]){
                  flag = false;
                  break;
                }
                  if(flag)
                  cout<<i<<" ";     
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
           
            if (j == M)
                cout<<"Pattern found at index "<< i<<endl;
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M ){
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
 
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            t = (t + q);
        }
    }
}


//     The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
//     Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values of all the substrings
//     of txt[] match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.
 

// solved on hackerrank:

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define q 7717
using namespace std;

int getAns(string& s, string& p){
    int n = s.length();
    int m = p.length();
    int pv=0, sv=0;
    int h = 1; int d = 256;
    
    for(int i=0; i<m-1; i++){
        h = (h * d)%q;
    }
    
    for(int i=0; i<m; i++){
        pv = (d * pv + p[i])%q;
        sv = (d * sv + s[i])%q;
    }
    
    int ans = 0;
    
    for(int i=0; i<=n-m; i++){
        
        if(sv==pv){
            bool flag = true;
            
            for(int j=0; j<m; j++){
                if(s[i+j] != p[j]){
                    flag = false;
                    break;
                }
            }
            
            if(flag == true){
                ans++;
            }
        }
        
        if(i<n-m){
            sv = (d*(sv - s[i]*h) + s[i+m])%q;
 
            if (sv < 0)
            sv = (sv + q);
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

