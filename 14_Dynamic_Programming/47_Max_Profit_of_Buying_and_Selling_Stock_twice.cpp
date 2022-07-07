// already covered in array section. 

int maxProfit(vector<int>&price){
    int n = price.size();
    int buy1 = INT_MAX; int buy2 = INT_MAX;
    int profit1 = INT_MIN; int profit2 = INT_MIN;
    
    for(int i=0; i<n; i++){
        buy1 = min(buy1, price[i]);
        profit1 = max(profit1, price[i]-buy1);
        buy2 = min(buy2, price[i]-profit1);
        profit2 = max(profit2, price[i]-buy2);
    }
    
    return profit2;
}


// using DP approach:
// we are traversing the dp array twicw once from back by taking the max value in consideration.
// next time we are traversing the array from front by considering the min value from front and keep on subtracting the values from the current
// array element.


int maxProfit(vector<int>&price){
    int n = price.size();
    int dp[n] = {0};
    int ma = price[n-1]; int mi = price[0];
    
    for(int i=n-2; i>=0; i--){
        ma = max(ma, price[i]);
        dp[i] = max(dp[i+1], ma - price[i]);
    }
    
    for(int i=1; i<n; i++){
        mi = min(mi, price[i]);
        dp[i] = max(dp[i-1], dp[i]+price[i]-mi);
    }
    
    return dp[n-1];
}
