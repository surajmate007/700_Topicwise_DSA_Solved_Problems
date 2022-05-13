// we are first finding the leftmax nad rightmax from corresponding left and right sides and then keep on finding the amount of water
// that can be trapped in between current index and leftmax or current index and rightmax based on the value at left or right index

long long trappingWater(int arr[], int n){
        int l=0; int h=n-1; int leftmax=0, rightmax=0; long long ans = 0;
        while(l < h){
            if(arr[l] <= arr[h]){
                if(arr[l] > leftmax){
                    leftmax = arr[l];
                }
                else{
                    ans += (leftmax-arr[l]);
                }
                l++;
            }
            
            else{
                if(arr[h] > rightmax){
                    rightmax = arr[h];
                }
                else{
                    ans += (rightmax-arr[h]);
                }
                h--;
            }
        }
        
        return ans;
    }
