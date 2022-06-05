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

// letcode problem. Both are different problems

class Solution {
public:
    int minSwaps(string s) {
        int open=0,incorrect=0;
        for(char c:s){
            if(!open and c==']') incorrect++;
            else if(c=='[') open++;
            else open--;
        }
        return (incorrect+1)/2;
    }
};
