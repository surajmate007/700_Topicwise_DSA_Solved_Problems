// simple approach using sorting.

class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);
        vector<int> last = arr[0];
        int ans = 0;
        
        for(int i=1; i<n; i++){
            if(arr[i][0] < last[0] and arr[i][1] < last[1]){
                ans++;
            }
            else{
                last = arr[i];
            }
        }
        
        return ans;
    }
};
