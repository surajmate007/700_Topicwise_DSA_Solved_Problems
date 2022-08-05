// Simple Code:

class Solution {
  public:
  
    long long maximumMultiple(int n, int vec[]) {
        vector<long long> arr;
        for(int i=0; i<n; i++){
            arr.push_back(vec[i]);
        }
        
        sort(arr.begin(), arr.end());
        
        int c = (n/2)-1;
        
        // When both +ve and -ve are same
        if(arr[c] < 0 and arr[c+1] > 0){
            reverse(arr.begin()+c+1, arr.end());
        }
        
        long long ans = LLONG_MIN;
        
        int i = 0; int j = n-1;
        while(i < j){
            long long pro = arr[i] * arr[j];
            ans = max(ans, pro);
            i++; j--;
        }
        
        return ans;
    }
};


// code written by me. here we are taking care of all the possible conditions.

class Solution {
  public:
  
  long long getAns(vector<long long> arr, int i, int j){
      long long ans = LLONG_MIN;
     
      while(i < j){
          long long pro = arr[i] * arr[j];
        //   cout<<arr[i]<<" "<<arr[j]<<" "<<pro<<endl;
          ans = max(ans, pro);
          i++; j--;
      }
      
      return ans;
  }
  
    long long maximumMultiple(int n, int vec[]) {
        vector<long long> arr;
        for(int i=0; i<n; i++){
            arr.push_back(vec[i]);
        }
        
        sort(arr.begin(), arr.end());
        int c = (n/2)-1;
        
        if(arr[c] == 0 or arr[c+1] == 0){
            // cout<<"cat0"<<endl;
            return 0;
        }
        
        // if half +ve and half -ve:
        if(arr[c] < 0 and arr[c+1] > 0){
            // cout<<"cat1"<<endl;
            reverse(arr.begin()+c+1, arr.end());
            long long ans = getAns(arr, 0, n-1);
            return ans;
        }
        
        // if more +ve:
        if(arr[c] > 0 and arr[c+1] > 0){
            // cout<<"cat2"<<endl;
            int ng = 0; vector<long long> pos;
            for(int i=0; i<n; i++){
                if(arr[i] > 0){
                    pos.push_back(arr[i]);
                }
                else{
                    ng++;
                }
            }
        
            long long ans = getAns(pos, 0, pos.size()-ng-1);
            return ans;
        }
        
        // if more are -ve:
        if(arr[c] < 0 and arr[c+1] < 0){
            // cout<<"cat3"<<endl;
            int ps = 0; vector<long long> neg;
            for(int i=0; i<n; i++){
                if(arr[i] < 0){
                    neg.push_back(arr[i]);
                }
                else{
                    ps++;
                }
            }
            
            long long ans = getAns(neg, ps, neg.size()-1);
            return ans;
        }
        
        return -1;
    }
};
