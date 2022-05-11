// using 2 array approach one stores min and other stores max element.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size()-1;
        vector<int> mn(n+1, 0);
        vector<int> mx(n+1, 0);
        mn[0] = prices[0]; mx[n] = prices[n];
        for(int i=1; i<=n; i++){
            mn[i] = min(mn[i-1], prices[i]);
            mx[n-i] = max(mx[n-i+1], prices[n-i]);
        }
        int ans = 0;
        
        for(int i=0; i<=n; i++){
            ans = max(ans, (mx[i] - mn[i]));
        }
        
        return ans;
    }
};

// keeping track of min value and subtracting it from current array values and finding the maximum difference.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int ans=0; int diff=0;
        for(int i=0; i<prices.size(); i++){
            mn = min(mn, prices[i]);
            diff = prices[i]-mn;
            ans = max(ans, diff);
        }
        
        return ans;
    }
};



