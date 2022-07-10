// Recursive code :

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int minJumps(vector<int>& arr, int n, int k, int idx){
    
    if(idx == n-1){
        return 0;
    }

    int one = INT_MAX;
    for(int i=idx+1; i<=idx+k; i++){
        if(i < n){
            one = min(one, abs(arr[idx] - arr[i]) + minJumps(arr, n, k, i));
        }
    }

    return one;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = minJumps(arr, n, k, 0);
    cout<<ans<<endl;

    return 0;
}


// Memoised Version of the code:

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int minJumps(vector<int>& arr, int n, int k, int idx, vector<int>& dp){
    
    if(idx == n-1){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }

    int one = INT_MAX;
    for(int i=idx+1; i<=idx+k; i++){
        if(i < n){
            one = min(one, abs(arr[idx] - arr[i]) + minJumps(arr, n, k, i, dp));
        }
    }

    return dp[idx]= one;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> dp(n+1, -1);

    int ans = minJumps(arr, n, k, 0, dp);
    cout<<ans<<endl;

    return 0;
}


// Tabulation :

