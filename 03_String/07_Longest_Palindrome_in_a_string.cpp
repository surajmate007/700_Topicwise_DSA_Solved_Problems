// This is the easiest aproach for this problem:

bool isPalin(string s){
      int i=0; int j=s.length()-1;
      while(i< j){
          if(s[i] == s[j]){
              i++; j--;
          }
          else{
              return false;
          }
      }
      return true;
  }
  
    string longestPalin (string s) {
        if(s.length() == 1){
            return s;
        }
        int n = s.length();
        int len = INT_MIN; string ans = "";
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalin(s.substr(i, j-i+1))){    // j-i+1 reprersents the length of the substr.
                    if(j-i+1 > len){
                        len = j-i+1;
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        
        return ans;
}
