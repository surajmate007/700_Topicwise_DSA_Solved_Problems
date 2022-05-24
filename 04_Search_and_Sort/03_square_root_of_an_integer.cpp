// ww will simplr traverse upto the sqrt of the givenN and check whether the sqare of the number is less than
// the given N.

int countSquares(int N) {
        int p = sqrt(N); int ans = 0;
        for(int i=1; i<=p; i++){
            if(i*i < N){
                ans++;
            }
        }
        
        return ans;
    }
