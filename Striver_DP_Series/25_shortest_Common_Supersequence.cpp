// Recursive code:


#include<bits/stdc++.h>
string final = "";
int len;

int getAns(string& a, string& b, int n, int m, int idx1, int idx2, string ds){
    if(idx1 >= n){
        ds += b.substr(idx2);
        int l = ds.length();
        if(l < len){
            len = l;
            final = ds;
        }
        return l;
    }
    
    if(idx2 >= m){
        ds += a.substr(idx1);
        int l = ds.length();
        if(l < len){
            len = l;
            final = ds;
        }
        return l;
    }
    
    int ans = 1e9;
    if(a[idx1] == b[idx2]){
        ans = getAns(a, b, n, m, idx1+1, idx2+1, ds+a[idx1]);
    }
    
    else{
        int ans1 = getAns(a, b, n, m, idx1+1, idx2, ds+a[idx1]);
        int ans2 = getAns(a, b, n, m, idx1, idx2+1, ds+b[idx2]);
        ans = min(ans1, ans2);
    }
    
    return ans;
}

string shortestSupersequence(string a, string b){
    int n = a.length();
    int m = b.length();
    len = 1e9;
    
	int val = getAns(a, b, n, m, 0, 0, "");
    return final;
}



// Memoised:
// using dp approach to form the string and then reverse it.

#include<bits/stdc++.h>

string shortestSupersequence(string a, string b){
    int n = a.length();
    int m = b.length();
    
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 or j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string ans = "";
    
    int i=n, j=m;
    
    while(i>0 and j>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans += a[i-1];
            i--;
        }
        else{
            ans += b[j-1];
            j--;
        }
    }
    
    while(i>0){
        ans += a[i-1];
        i--;
    }
    while(j>0){
        ans += b[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}
