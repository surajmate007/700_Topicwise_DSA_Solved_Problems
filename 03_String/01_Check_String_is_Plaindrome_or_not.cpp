// we will simply use 2 pointer approach to check this:

class Solution{
public:	
	int isPalindrome(string S){
	    int i=0; int j = S.length()-1;
	    while(i < j){
	        if(S[i] == S[j]){
	            i++; j--;
	        }
	        else{
	            return 0;
	        }
	    }
	    
	    return 1;
	}

};

// we can also check it by reverseing the string and then matching them both.

class Solution{
public:	
	int isPalindrome(string S){
	    string A = S;
	    reverse(S.begin(), S.end());
	    if(A == S){
	        return 1;
	    }
	    else{
	        return 0;
	    }
	}

};
