// simple code

int minimumNumberOfSwaps(string s){
        int cnt = 0; int swap = 0; int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == ']'){
                cnt++;
                if(cnt > 0){
                    swap += cnt;
                }
            }
            else{
                cnt--;
            }
        }
        
        return swap;
}
