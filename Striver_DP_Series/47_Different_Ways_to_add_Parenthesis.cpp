// Recursive:


class Solution {
public:
    
    vector<int> getAns(string s, int lo, int hi){
        
        if(lo == hi){
            return {s[lo]-'0'};
        }
        
        vector<int> res;
        
        for(int k=lo; k<hi; k++){
            vector<int> res1, res2;
            if(s[k] == '-'){
                res1 = getAns(s, lo, k-1);
                res2 = getAns(s, k+1, hi);
                
                for(int i=0; i<res1.size(); i++){
                    for(int j=0; j<res2.size(); j++){
                        res.push_back(res1[i] - res2[j]);
                    }
                }
            }
            
            else if(s[k] == '+'){
                res1 = getAns(s, lo, k-1);
                res2 = getAns(s, k+1, hi);
                
                for(int i=0; i<res1.size(); i++){
                    for(int j=0; j<res2.size(); j++){
                        res.push_back(res1[i] + res2[j]);
                    }
                }
            }
            
            else if(s[k] == '*'){
                res1 = getAns(s, lo, k-1);
                res2 = getAns(s, k+1, hi);
                
                for(int i=0; i<res1.size(); i++){
                    for(int j=0; j<res2.size(); j++){
                        res.push_back(res1[i] * res2[j]);
                    }
                }
            }
        }
        
        if(res.size() == 0){
            return {stoi(s)};
        }
        return res;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return getAns(expression, 0, n-1);
    }
};



// Memoised:

class Solution {
public:
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] < '0') {
                vector<int> v1 = diffWaysToCompute(input.substr(0, i));
                vector<int> v2 = diffWaysToCompute(input.substr(i + 1));
                for (auto i1 : v1) for (auto i2 : v2) switch (input[i]) {
                    case '+': res.push_back(i1 + i2); break;
                    case '-': res.push_back(i1 - i2); break;
                    case '*': res.push_back(i1 * i2);
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};
