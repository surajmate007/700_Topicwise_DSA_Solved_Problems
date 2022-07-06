// my own written code using dp.

#include<iostream>
#include<cstring>
using namespace std;

int getAns(int arr[], int n){
    int dp[n]; int last[n];
    memset(last, 0, sizeof(last));
    dp[0] = arr[0]; dp[1] = arr[1]+arr[0];
    last[1] = 1;

    for(int i=2; i<n; i++){
        dp[i] = dp[i-2] + arr[i];             // first considering sum of arr[i] and dp[i-2];

        if(last[i-1] == 0 and dp[i] < dp[i-1]+arr[i]){        // if the previous sun didnt include the last element then we can include current element in
                                                              // the previous sum and we will make the last element as included.
            dp[i] = dp[i-1] + arr[i];
            last[i] = 1;
        }

        if(last[i-1] == 1 and dp[i] < dp[i-1] + arr[i] - arr[i-2]){     // if previous sum included the last element then we have to chwekc wehther the 
            dp[i] = dp[i-1] + arr[i] - arr[i-2];                        // sum is less than the sum upto last element excluding the last of last element.
            last[i] = 1;
        }

        if(dp[i] <= dp[i-1]){                 // of the dp sum so far is less than or equal to the dp sum upto last element then there is no point in
            dp[i] = dp[i-1];                  // including the last element in the current dp sum.
            last[i] = 0;
        }
    }

    for(int i=0; i<n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return dp[n-1];
}

int main(){
    int n; cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = getAns(arr, n);
    cout<<"Ans : "<<ans<<endl;

    return 0;
}




// sum[i] : Stores result for subarray arr[0..i], i.e.,
//          maximum possible sum in subarray arr[0..i]
//          such that no three elements are consecutive.

// sum[0] = arr[0]

// Note : All elements are positive
// sum[1] = arr[0] + arr[1]

// We have three cases
// 1) Exclude arr[2], i.e., sum[2] = sum[1]
// 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2]
// 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2] 
// sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

// In general,
// We have three cases
// 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
// 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
// 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 
// sum[i] = max(sum[i-1], sum[i-2] + arr[i],
//              sum[i-3] + arr[i] + arr[i-1])


// C++ program to find the maximum sum such that
// no three are consecutive
#include <bits/stdc++.h>
using namespace std;

// Returns maximum subsequence sum such that no three
// elements are consecutive
int maxSumWO3Consec(int arr[], int n)
{
  // Stores result for subarray arr[0..i], i.e.,
  // maximum possible sum in subarray arr[0..i]
  // such that no three elements are consecutive.
  int sum[n];

  // Base cases (process first three elements)
  if (n >= 1)
    sum[0] = arr[0];

  if (n >= 2)
    sum[1] = arr[0] + arr[1];

  if (n > 2)
    sum[2] = max(sum[1], max(arr[1] +
              arr[2], arr[0] + arr[2]));

  // Process rest of the elements
  // We have three cases
  // 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
  // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
  // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
  for (int i = 3; i < n; i++)
    sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]),
          arr[i] + arr[i - 1] + sum[i - 3]);

  return sum[n - 1];
}

// Driver code
int main()
{
  int arr[] = { 100, 1000 };
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << maxSumWO3Consec(arr, n);
  return 0;
}


