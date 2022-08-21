// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the
// characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a
// character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

// Return the final string after all such shifts to s are applied.

// Constraints:

// 1 <= s.length, shifts.length <= 5 * 10^4
// shifts[i].length == 3
// 0 <= starti <= endi < s.length
// 0 <= directioni <= 1
// s consists of lowercase English letters.
// clearly we cant do it in order of n^2.

// Here we are using the concept of prefix sum.
// For every range we are setting the start of the range as -1 or +1 based on the direction and also set the end+1 index as opposite +1 or -1 based on
// the direction.


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> pre (n+1, 0);
        
        for(auto e : shifts){
            int a = e[0]; int b = e[1]; int d = e[2];
            if(d == 0){
                pre[a] += -1;
                pre[b+1] += 1;
            }
            else{
                pre[a] += 1;
                pre[b+1] += -1;
            }
        }
        
        for(int i=1; i<n; i++){
            pre[i] = pre[i] + pre[i-1];
        }
        
        string ans = "";
        for(int i=0; i<n; i++){
            int val = (s[i]-'a' + pre[i])%26;
            
            if(val < 0){
                ans += ('a' + (26 + val));
            }
            else{
                ans += ('a' + val);
            }
        }
        
        return ans;
    }
};
