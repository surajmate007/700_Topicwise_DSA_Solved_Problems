// Original solution but giving TLE.

class Solution{
    public:
    //Function to find the largest number after k swaps.
    void getAns(string str, int n, int k, string& ans){
        if(str > ans){
            ans = str;
            return;
        }
        
        if(k==0){
            return;
        }
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(str[j] > str[i]){
                    swap(str[i], str[j]);
                    getAns(str, n, k-1, ans);
                    swap(str[i], str[j]);
                }
            }
        }
    }
    
    string findMaximumNum(string str, int k){
        int n = str.length();
        string ans = str;
        getAns(str, n, k, ans);
        
        return ans;
    }
};


// New solution:

class Solution{
    public:
    //Function to find the largest number after k swaps.
    string solve(string &s, int i, int n, int k){
        if(i>=n || k<=0) return s;
        string temp=s;
        for(int j=i;j<n;j++){
            if(s[j]>s[i]){
                swap(s[j],s[i]);
                temp=max(temp,solve(s,i+1,n,k-1));
                swap(s[j],s[i]);
            }
        }
        
        temp=max(temp,solve(s,i+1,n,k)); //no swapping
        return temp;
    }
    
    string findMaximumNum(string str, int k){
       return solve(str,0,str.size(),k);
    }
};
