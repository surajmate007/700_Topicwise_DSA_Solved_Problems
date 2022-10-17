// simple code using finding the min on left and right and then multiplying.

class Solution {
public:
    const int mod = 1e9+7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n), right(n);
        deque<int> dq; long long ans = 0;

        for(int i=0; i<n; i++){
            while(!dq.empty() and arr[dq.back()] > arr[i]){
                dq.pop_back();
            }
            if(dq.empty()){
                left[i] = i+1;
            }
            else{
                left[i] = i-dq.back();
            }
            dq.push_back(i);
        }
        dq.clear();
        for(int i=n-1; i>=0; i--){
            while(!dq.empty() and arr[dq.back()] >= arr[i]){
                dq.pop_back();
            }
            if(dq.empty()){
                right[i] = n-i;
            }
            else{
                right[i] = dq.back()-i;
            }
            dq.push_back(i);
        }
        
        for(int i=0; i<n; i++){
            ans = (ans%mod + ((right[i] * left[i])%mod * arr[i])%mod)%mod;
        }

        return ans;
    }
};
