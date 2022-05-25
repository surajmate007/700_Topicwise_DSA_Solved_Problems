class Solution{
public:
    int inSequence(int A, int B, int C){
        if(C==0){
            if(A==B){
                return 1;
            }
            else{
                return 0;
            }
        }
        else if(B==A){
            return 1;
        }
        else if((B-A)%C==0 and B>A and C>0){
            return 1;
        }
        else if((B-A)%C==0 and B<A and C<0){
            return 1;
        }
        else{
            return 0;
        }
    }
};
