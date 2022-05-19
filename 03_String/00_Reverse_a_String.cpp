// we can use 2 pointer method to reverse the string.
// one starting from 0 index and other starting from last index.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0; int j = s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++; j--;
        }
    }
};

// one line code:

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
