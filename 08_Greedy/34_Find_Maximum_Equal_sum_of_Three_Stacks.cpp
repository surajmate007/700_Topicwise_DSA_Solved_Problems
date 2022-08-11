// This is the simple solution for this problem.
// here first we are checking the total sum of all arrays are equal or not if equal then this will be the answer.
// if not then we are checking max sum using pointers approach where we are keeping three pointers at the end of the arrays and then keep on
// moving to the front by summing up the elements. The conditions for movement are shown in conditionals.

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &a1,vector<int> &a2,vector<int> &a3){
        int i= 0; int j = 0; int k = 0;
        int t1 = accumulate(a1.begin(), a1.end(), 0);
        int t2 = accumulate(a2.begin(), a2.end(), 0);
        int t3 = accumulate(a3.begin(), a3.end(), 0);
        int s1=0, s2=0, s3=0;
        int ans = 0;
        
        while(i<n1 and j<n2 and k<n3){
            int r1 = t1-s1; int r2 = t2-s2; int r3 = t3-s3;
            
            if(r1 == 0 or r2 == 0 or r3 == 0){
                ans = 0;
                break;
            }
            
            if(r1 == r2 and r1 == r3){
                ans = r1;
                break;
            }
            
            if(max({r1, r2, r3}) == r1){
                s1 += a1[i]; i++;
            }
            
            else if(max({r1, r2, r3}) == r2){
                s2 += a2[j]; j++;
            }
            
            else{
                s3 += a3[k]; k++;
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
