// Just create all the subsets from the given array and find their sum.

void getans(vector<int>& ans, vector<int> arr, int idx, int n, int& sum){
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        
        sum += arr[idx];
        getans(ans, arr, idx+1, n, sum);
        sum -= arr[idx];
        getans(ans, arr, idx+1, n, sum);
        
    }
        
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> ans;
        int sum = 0;
        getans(ans, arr, 0, N, sum);
        return ans;
    }


// In this solution we are telling whether the sum is possible in the given array.
class Solution{   
public:
    bool getAns(vector<int>& arr, int idx, int n, int sum, vector<vector<int>>& dp){
        if(sum == 0){
            return true;
        }
        if(idx >= n or sum < 0){
            return false;
        }
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        
        return dp[idx][sum] = getAns(arr, idx+1, n, sum-arr[idx], dp) or getAns(arr, idx+1, n, sum, dp);
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return getAns(arr, 0, n, sum, dp);
    }
};
