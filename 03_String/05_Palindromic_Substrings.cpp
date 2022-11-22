// siple code but I am not able to write the recursion for this code. 😢🥺

class Solution {
public:
    int isPalin(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return 0;
            }
            start++; end--;
        }
        return 1;
    }

    int getAns(string& s, int n){
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                ans += isPalin(s, i, j);
            }
        }
        return ans;
    }

    int countSubstrings(string s) {
        int n = s.length();
        return getAns(s, n);
    }
};
