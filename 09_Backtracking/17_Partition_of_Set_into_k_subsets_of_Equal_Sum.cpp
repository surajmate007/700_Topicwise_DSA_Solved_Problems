// More intuitive solution.
// Revise very very frequently.

class Solution{
    public:
  
    void getAns(int a[], int n, int k, bool& flag, int cnt, int csum, int osum, vector<int>& visited){
    
        if(cnt == k-1){
            flag = true;
            return;
        }
      
        if(csum > osum){
            return;
        }
      
        if(csum == osum){
            return getAns(a, n, k, flag, cnt+1, 0, osum, visited);
            if(flag == true){
                return;
            }
        }
      
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                getAns(a, n, k, flag, cnt, csum+a[i], osum, visited);
                if(flag == true){
                    return;
                }
                visited[i] = 0;
            }
        }
        return;
    }
  
  
    bool isKPartitionPossible(int a[], int n, int k){
        if(k > n){
            return false;
        }
        if(k==1){
            return true;
        }
        int osum = 0;
        for(int i=0; i<n; i++){
            osum += a[i];
        }
        if(osum%k != 0){
            return false;
        }
        
        bool flag = false;
        osum = osum/k;
        vector<int> visited(n, 0);
        
        getAns(a, n, k, flag, 0, 0, osum, visited);
        
        return flag;
    }
};
