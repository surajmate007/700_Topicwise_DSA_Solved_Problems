class Solution{
  public:
    int minJumps(int arr[], int n){
        int pos = 0; int count = 0; int last = 0;
        while(pos < n-1){
            if(arr[pos] == 0){
                return -1;
            }
            int mx = 0;
            for(int i = last+1; i<= last+arr[pos]; i++){
                if(arr[i] > mx){
                    mx = arr[i];
                    last = i;
                }
            }
            
            pos += mx;
            count++;
        }
        return count+1;
    }
};
