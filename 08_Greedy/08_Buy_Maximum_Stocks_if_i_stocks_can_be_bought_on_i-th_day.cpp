class Solution{
  public:
    
    static bool comp(pair<int, int>& a, pair<int, int>& b){
        return a.first < b.first;
    }
    
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({price[i], i+1});
        }
        
        sort(vec.begin(), vec.end(), comp);
        
        int ans = 0; 
        for(int i=0; i<n; i++){
            if((vec[i].second * vec[i].first) < k){
                ans += vec[i].second;
                k -= (vec[i].second * vec[i].first);
            }
            else{
                ans += (k/vec[i].first);
                break;
            }
        }
        
        return ans;
    }
};
