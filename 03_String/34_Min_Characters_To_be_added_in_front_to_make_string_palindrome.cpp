// Here the approach is simple:
// 1. we will first compute the length of max palindromic substring starting from 0th index.
// 2. Then return all the remaining characters which are not part of this substring.


bool isPalin(string s){
        int i=0; int j=s.length()-1;
        while(i<j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int minChar(string s){
        int i=0; int n = s.length();
        int count = 0;
        while(i < n){
            if(isPalin(s.substr(0, i+1))){
                count = max(count, i+1);
            }
            i++;
        }
        
        return n - count;
        
}
