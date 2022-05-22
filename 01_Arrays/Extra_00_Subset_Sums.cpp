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
