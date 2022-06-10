// easy solution

class Solution{
public:
    int minimumDays(int S, int N, int M){
        if(M > N){
            return -1;
        }
        
        if(S > 6){
            if((N-M)*6 < M){
                return -1;
            }
        }
       
        double d = (double)N/(double)M;
        return ceil(S/(d));
    }
};
