// Egg Dropping with bianry seacrh approach:


#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
using namespace std;
int memo[101][10001];

int eggDrop(int eggs, int floors)
{
    // If 'FLOORS' = 0 no drop needed.
    // If FL'OORS = 1 only 1 drop needed.
    if (floors <= 1)
        return floors;

    // If 'EGGS' = 1, gradually drop the egg from 1st floor to all the way up.
    if (eggs == 1)
        return floors;

    // If answer for given number of eggs and floors, return it.
    if (memo[eggs][floors] != -1)
        return memo[eggs][floors];

    // 'ANS' returns the final answer for current number of eggs and floors.
    int ans = INT_MAX, movesForUnbrokenEgss = 0, movesForBrokenEgss = 0;

    // 'LOW' and 'HIGH' pointers for binary search.
    int low = 1, high = floors;

    while (low < high)
    {

        // Computing mid floor to drop the egg from the mid floor.
        int mid = low + (high - low) / 2;

        // 'MOVES_FOR_BROKEN_EGGS' to store answer if egg is broken after falling from 'MID' floor.
        if (memo[eggs - 1][mid - 1] != -1)
            movesForBrokenEgss = memo[eggs - 1][mid - 1];
        else
            movesForBrokenEgss = eggDrop(eggs - 1, mid - 1);

        // 'MOVES_FOR_UNBROKEN_EGGS' to store answer if egg is not broken after falling from 'MID' floor.
        if (memo[eggs][floors - mid] != -1)
            movesForUnbrokenEgss = memo[eggs][floors - mid];
        else
            movesForUnbrokenEgss = eggDrop(eggs, floors - mid);

        // Move the binary search towards the case where number of egg drops are more.
        if (movesForBrokenEgss > movesForUnbrokenEgss)
            high = mid;
        else
            low = mid + 1;

        // Maximum number of egg drops for both the case.
        // Add 1 to represent the current egg drop.
        int temp = 1 + max(movesForBrokenEgss, movesForUnbrokenEgss);

        // Choose minimum of all the worst cases.
        ans = min(ans, temp);
    }

    // Storing the output for current numbers of eggs and floors.
    return memo[eggs][floors] = ans;
}

int main()
{
    int eggs, floors;
    cout << "Enter Eggs: ";
    cin >> eggs;
    cout << "Enter Floors: ";
    cin >> floors;
    
    // Initialize memo array with value -1.
    memset(memo, -1, sizeof(memo));

    cout << "Minimum number of moves required: " << eggDrop(eggs, floors);
}




// Simple Recursive Approach (gut giving TLE):
// Here n-- no. of eggs and k -- no. of floors.
// when no of eggs is only 1 then we will start from ground floor and try every single floor by droping the egg. Hence attempts required will be k.
// when we have 0 floors or only glound floor then the attempts will be no. of floors.
// now for more number of floors we will drop egg from every single floor and check whether it broke or not.
// if egg is btoken then we will reduce eggs by 1 and floor by 1.
// if not broken then we will check it in upper floors.

int eggDrop(int n, int k) {
       if(n==1){return k;}
       if(k==0 or k==1){
           return k;
       }
       int ans = INT_MAX;
       
       for(int i=1; i<=k; i++){
           int temp = 1 + max(eggDrop(n-1, i-1), eggDrop(n, k-i));
           ans = min(ans, temp);
       }
       
       return ans;
}


// Egg Dropping with binary search and memoisation:

class Solution {
public:
    int dp[110][10050];
    
    int getAns(int e, int k){
        if(e==1 or k==0 or k==1){
            return dp[e][k] = k;
        }
        
        if(dp[e][k] != -1){
            return dp[e][k];
        }
        
        int lo = 1; int hi = k; int ans = 1e9;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            
            int left = getAns(e-1, mid-1);
            int right = getAns(e, k-mid);
            ans = min(ans, 1 + max(left, right));
            
            if(left > right){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return dp[e][k] = ans;
    }
    
    int superEggDrop(int e, int k) {
        memset(dp, -1, sizeof(dp));
        return getAns(e, k);
    }
};



// Egg Dropping Memoized:

int dp[201][201];
    int getans(int n, int k){
        if(n==1 or k==0 or k==1){
            return k;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        int mn = INT_MAX;
        
        for(int i=1; i<=k; i++){
            int up, down;
            if(dp[n-1][i-1] != -1){
                down = dp[n-1][i-1];
            }
            else{
                down = getans(n-1, i-1);
            }
            
            if(dp[n][k-i] != -1){
                up = dp[n][k-i];
            }
            else{
                up = getans(n, k-i);
            }
            
            int temp = 1 + max(up, down);
            mn = min(mn, temp);
        }
        return dp[n][k] = mn;
    }
    
    int eggDrop(int n, int k) {
       memset(dp, -1, sizeof(dp));
       return getans(n, k);
}
