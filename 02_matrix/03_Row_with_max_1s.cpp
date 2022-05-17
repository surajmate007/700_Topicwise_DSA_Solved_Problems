// Brute Force
// we will traverse through all rows and find the sum of elements in each row, the row with max sum will be the final answer for this problem.

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1; int mx = 0;
	    for(int i=0; i<n; i++){
	        int sum = accumulate(arr[i].begin(), arr[i].end(), 0);
	        if(sum > mx){
	            mx = sum;
	            ans = i;
	        }
	    }
	    return ans;
	}
};

// more optimised solution

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        // code here
        int row = 0, col = m - 1, ans = -1;
        int one = 0;
        while (col >= 0 && row < n) {
            if (arr[row][col] == 1) {
                one = max(one, col);
                ans = max(ans, row);
                col--;
            }
            else row++;
        }
        return ans;
    }
