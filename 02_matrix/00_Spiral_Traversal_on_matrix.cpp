// first setting the bounds for the traversal using 4 variables top, down, left and right and then using one variable for representing the direction
// based on the value of direction we will decide from where to start and where to go.

vector<int> spirallyTraverse(vector<vector<int> > arr, int row, int col){
        int l, r, t, d;
        l=0, t=0, r=col-1, d=row-1;
        vector<int> ans;
        int direction = 0;
        while(l<=r and t<=d){
            if(direction == 0){
                for(int i=l; i<=r; i++){
                    ans.push_back(arr[t][i]);
                }
                t++;
                direction = (direction+1)%4;
            }
            else if(direction == 1){
                for(int i=t; i<=d; i++){
                    ans.push_back(arr[i][r]);
                }
                r--;
                direction = (direction+1)%4;
            }
            else if(direction == 2){
                for(int i=r; i>=l; i--){
                    ans.push_back(arr[d][i]);
                }
                d--;
                direction = (direction+1)%4;
            }
            else{
                for(int i=d; i>=t; i--){
                    ans.push_back(arr[i][l]);
                }
                l++;;
                direction = (direction+1)%4;
            }
        }
        return ans;
    }
