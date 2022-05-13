// finding maximum reach possible after every index and decrementing steps by 1. when steps becomes completely equal to 0 then updating the
// steps value from maxreach value.

int minJumps(int arr[], int n){
        if(n==1){
            return 0;
        }
        else if(arr[0] == 0){
            return -1;
        }
        else{
            int maxR = arr[0]; int step = arr[0]; int jumps = 1;
            for(int i=1; i<n; i++){
                if(i == n-1){
                    return jumps;
                }
                maxR = max(maxR, i+arr[i]);
                step--;
                if(step == 0){
                    jumps++;
                    if(i >= maxR){
                        return -1;
                    }
                    step += maxR-i;
                }
            }
        }
        
    }
