// going with the reverse approach. First finding the full length of the string and then traversing the given string from backwards
// and if the cha is digit then divide the final length else subtract. When the k==0 or k==final and s[i] != digit then it is the answer.

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        long long final = 0;
        string ans = "";

        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                final *= (s[i]-'0');
            }
            else{
                final++;
            }
        }

        for(int i=n-1; i>=0; i--){ 
            k %= final;
            if((k==0 or k==final) and isalpha(s[i])){
                ans = s[i];
                return ans;
            }
            if(isdigit(s[i])){
                final /= (s[i]-'0');
            }
            else{
                final--;
            }
        }
        
        return NULL;
    }
};
