// This problem canbe solved with greedy approach where we are greedily filling only those quantities having largest value to weight ratio.

class Solution{
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool comp(Item a, Item b){
        return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n){
        vector<pair<int, int>> pr;
        sort(arr, arr+n, comp);
        
        double ans = 0;
        
        for(int i=0; i<n; i++){
            if(W >= arr[i].weight){
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else{
                double per_gm = double(arr[i].value)/double(arr[i].weight);
                double money = per_gm * double(W);
                ans += money;
                break;
            }
            
            // cout<<ans<<endl;
        }
        
        return ans;
    }
        
};
