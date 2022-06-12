// Revise frequently.
// We are applying Greedy approach where we are always trying to subtract 9 from the number and tru to keep as minimum number as possible 
// to put at the front.


class Solution{
  public:
    string smallestNumber(int S, int D){
        string ans = ""; int len = D; int num = 9;
        while(D){
            while(num>=0){
                if(S >= num+1){
                    S -= num;
                    ans = to_string(num) + ans;
                    
                    break;
                }
                else{
                    num --;
                }
            }
            D--;
        }
        
        if(S == 1){
            ans[0] = ans[0]+1;
            S = 0;
        }
        
        if(S != 0){
            return "-1";
        }
        
        return ans;
    }
};
