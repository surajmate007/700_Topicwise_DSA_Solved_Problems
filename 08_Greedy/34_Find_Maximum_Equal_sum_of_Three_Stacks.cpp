// This is the simple solution for this problem.
// here first we are checking the total sum of all arrays are equal or not if equal then this will be the answer.
// if not then we are checking max sum using pointers approach where we are keeping three pointers at the end of the arrays and then keep on
// moving to the front by summing up the elements. The conditions for movement are shown in conditionals.

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int i=n1-2; int j=n2-2; int k=n3-2; int ans = 0;
        int si = s1[n1-1]; int sj = s2[n2-1]; int sk = s3[n3-1];
    
        int sa = accumulate(s1.begin(),s1.end(),0);
        int sb = accumulate(s2.begin(),s2.end(),0);
        int sc = accumulate(s3.begin(),s3.end(),0);
        
        if(s1 == s2 ans s1 == s3){
            return s1;
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
            // cout<<si<<" "<<sj<<" "<<sk<<endl;
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


// Better approach:

int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
       --n1;
       --n2;
       --n3;
       reverse(s1.begin(),s1.end());
       reverse(s2.begin(),s2.end());
       reverse(s3.begin(),s3.end());
       int sum1=accumulate(s1.begin(),s1.end(),0);
       int sum2=accumulate(s2.begin(),s2.end(),0);
       int sum3=accumulate(s3.begin(),s3.end(),0);
       while(n1>=0 && n2>=0 && n3>=0){
           if(sum1==sum2 && sum2==sum3) return sum1;
           if(sum1>sum2) sum1-=s1[n1--];
           if(sum2>sum3) sum2-=s2[n2--];
           if(sum3>sum1) sum3-=s3[n3--];
       }
       return 0;
   }
