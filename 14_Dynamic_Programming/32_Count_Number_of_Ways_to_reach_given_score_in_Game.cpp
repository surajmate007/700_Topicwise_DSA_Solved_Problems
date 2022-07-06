// using dp approach.
// fristly we are filling the 0th row by only cinsiderring the value 3. then we are applying loop on other elements in the array upto value of n. 

long long int count(long long int n){
    int a[] = {3, 5, 10};
	long long dp[3][n+1];
	dp[0][0]=1; dp[1][0]=1; dp[2][0]=1;
	
	for(int j=1; j<=n; j++){
	    if(j%3 == 0){
	        dp[0][j] = 1;
	    }
	    else{
	        dp[0][j] = 0;
	    }
	}
	
	for(int i=1; i<3; i++){
	    for(int j=1; j<=n; j++){
	        if(a[i] <= j){
	            dp[i][j] = dp[i][j-a[i]] + dp[i-1][j];
	        }
	        else{
	            dp[i][j] = dp[i-1][j];
	        }
	    }
	}
	
	return dp[2][n];
}
