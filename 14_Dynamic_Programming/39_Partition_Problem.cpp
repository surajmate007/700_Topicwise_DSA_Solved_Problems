// we will first find whether the sum is even or odd. If it is odd then we will return 0 since we cant divide such such into two parts
// if even we will then check for sum/2 inot the array if sum/2 is possible to form (we will check it using dp like 0-1 knapsack problem) 
// then we will understand that it is feasible to form the equal sums from the array.

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
