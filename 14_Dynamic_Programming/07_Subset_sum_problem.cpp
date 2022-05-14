// using same approach like knapsack problem. Here only instead of finding max of two entities we are finding the or between the two values.

class Solution{
public:
    int equalPartition(int N, int arr[]){
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += arr[i];
        }
        if(sum % 2 == 1){
            return 0;
        }
        sum = sum/2;
        bool dp[N+1][sum+1];
        for(int i=0; i<N+1; i++){
            for(int j=0; j<sum+1; j++){
                if(j==0){
                    dp[i][j] = true;
                }
                else if(i==0){
                    dp[i][j] = false;
                }
                else if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]]) or dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[N][sum] == true){
            return 1;
        }
        else{
            return 0;
        }
    }
};
