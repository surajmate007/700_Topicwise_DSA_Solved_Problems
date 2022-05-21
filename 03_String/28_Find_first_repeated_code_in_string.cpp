// Brute force approach:

// We cant use Moores voting algorithm because this algo only works when the maximium occuring element is more than (size/2) times of the array.

class Solution{
  public:
    string secFrequent (string arr[], int n){
        unordered_map<string, int> mp;
        string ans;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        vector<int> vec;
        int c = 0;
        for(auto e : mp){
            vec.push_back(e.second);
            c++;
        }
        
        sort(vec.begin(), vec.end());
        int cnt = vec[c-2];
        
        for(auto e : mp){
            if(cnt == e.second){
                ans = e.first;
            }
        }
        
        return ans;
    }
};


// Optimised approach from reference github profile

class Solution{
  public:
    string secFrequent (string arr[], int n){
        unordered_map<string, int> mp;
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            mx = max(mx, mp[arr[i]]);
        }
        int lmax = INT_MIN;
        string ans;
        for(auto it : mp){
            if(it.second != mx and it.second > lmax){
                lmax = it.second;
                ans = it.first;
            }
        }
        
        return ans;
    }
};

// Moores voting algorithm for finding the maximum repeated element in the array is as follows:

int maxFreq(int *arr, int n) {
    //using moore's voting algorithm
    int res = 0;
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[res]) {
            count++;
        } else {
            count--;
        }
         
        if(count == 0) {
            res = i;
            count = 1;
        }
         
    }
    return arr[res];
}

