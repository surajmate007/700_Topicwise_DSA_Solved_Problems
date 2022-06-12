// This is the simple solution for this problem.
// here first we are checking the total sum of all arrays are equal or not if equal then this will be the answer.
// if not then we are checking max sum using pointers approach where we are keeping three pointers at the end of the arrays and then keep on
// moving to the front by summing up the elements. The conditions for movement are shown in conditionals.

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int i=n1-2; int j=n2-2; int k=n3-2; int ans = 0;
        int si = s1[n1-1]; int sj = s2[n2-1]; int sk = s3[n3-1];
        int sa=0, sb=0, sc=0;
        for(int i=0; i<n1; i++){
            sa += s1[i];
        }
        
        for(int i=0; i<n2; i++){
            sb += s2[i];
        }
        
        for(int i=0; i<n3; i++){
            sc += s3[i];
        }
        
        if(sa == sb and sa == sc){
            return sa;
        }
        
        while(i>=-1 and j>=-1 and k>=-1){
            if(si == sj and si==sk){
                ans = si;
                
                if(i==-1 or j==-1 or k==-1){
                    break;
                }
                
                si += s1[i]; sj += s2[j]; sk += s3[k];
                i--; j--; k--;
            }
            
            else if(min({si, sj, sk}) == si){
                si += s1[i]; i--;
            }
            
            else if(min({si, sj, sk}) == sj){
                sj += s2[j]; j--;
            }
            
            else{
                sk += s3[k]; k--;
            }
        }
        
        return ans;
    }
};
