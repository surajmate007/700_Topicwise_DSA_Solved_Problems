// simple code using recursion:

class Solution{
	public:
	
	int getWinner(int n, int x, int y, bool turn){
	    if(n < 0){
	        return 0;
	    }
	    
	    if(n==x or n==y or n==1){
	        if(turn == true){
	            return 1;
	        }
	        else{
	            return 0;
	        }
	    }
	    
	    if(getWinner(n-x, x, y, !turn) == 1){
	        return 1;
	    }
	    
	    if(getWinner(n-y, x, y, !turn) == 1){
	        return 1;
	    }
	    
	    if(getWinner(n-1, x, y, !turn) == 1){
	        return 1;
	    }

	    return 0;
	}
	
	int findWinner(int n, int x, int y){
		return getWinner(n, x, y, 1,);
	}
};


// to convert it into dp:

class Solution{

	public:
	
	int findWinner(int n, int x, int y){
	    bool dp[n+1];
	    dp[0] = false;
	    dp[1] = true;
	    
	    for(int i=2; i<=n; i++){
	        if(i-1 >= 0 and dp[i-1]==false){
	            dp[i] = true;
	        }
	        else if(i-x >= 0 and dp[i-x]==false){
	            dp[i] = true;
	        }
	        else if(i-y >= 0 and dp[i-y]==false){
	            dp[i] = true;
	        }
	        else{
	            dp[i] = false;
	        }
	    }
	    
	    return dp[n];
	}

};
