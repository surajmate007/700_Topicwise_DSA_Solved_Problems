// Simple modification of rectangle with largest sum.

class Solution{
    public:
    // The following function returns the leftmost and rightmost indices (as a vector) of the longest segment with sum 0 in an array.
    vector<int>longestSegment(vector<int>&tmp) {
        int sum=0,len=0;
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<tmp.size();i++) {
            sum+=tmp[i];
            if(sum==0) {
                len=i+1;
                ans={0,i};
            }
            if(m.find(sum)!=m.end()) {
                if(len<i-m[sum]) {
                    len=i-m[sum];
                    ans={m[sum]+1,i};
                }
            }
            else {
                m[sum]=i;
            }
        }
        return ans;
    }
    
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a) {
        // 'maxDim' stores the area of the largest rectangle with sum 0
        // 'maxCol' stores the no. of columns of the largest rectangle with sum 0
        int row=a.size(),col=a[0].size(),maxDim=0,maxCol=0;
        
        // 'topLeft' and 'bottomRight' stores the coordinates of top left and bottom right corners of the largest rectangle with sum 0
        vector<int>topLeft,bottomRight;
        vector<vector<int>>dp(row,vector<int>(col));
        // dp[i][j] = a[0][j] + a[1][j] + a[2][j] + ... + a[i][j]
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                dp[i][j]=(i>0?a[i][j]+dp[i-1][j]:a[i][j]);
            }
        }
        // Apply Kadane's algorithm for matrix
        int rowUp = 0;
        
        while(rowUp < row){
            for(int rowDown=rowUp;rowDown<row;rowDown++) {
                vector<int>tmp(col);
                for(int k=0;k<col;k++) {
                    tmp[k]=dp[rowDown][k]-(rowUp>0?dp[rowUp-1][k]:0);
                }
                vector<int>ans=longestSegment(tmp);
                // 'ans' is storing leftmost and rightmost columns of rectangle with sum 0 if exists
                if(!ans.empty()) {
                    // no. of columns of the rectangle = ans[1]-ans[0]+1
                    // no. of rows of the rectangle = rowDown-rowUp+1
                    int currDim=(ans[1]-ans[0]+1)*(rowDown-rowUp+1);
                    // compare with previous results and take the rectangle with maximum area 
                    if(maxDim<currDim || (maxDim==currDim && maxCol<ans[1]-ans[0]+1)) {
                        maxDim=currDim;
                        maxCol=ans[1]-ans[0]+1;
                        // update the top left and bottom right corners
                        topLeft={rowUp,ans[0]};
                        bottomRight={rowDown,ans[1]};
                    }
                }
            }
            rowUp++;
        }
        // if no rectangle was found then return -1
        if(maxDim==0) {
            return {{-1}};
        }
        // Fetch the values of the rectangle whose top left and bottom right corners are given by the vectors 'topLeft' and 'bottomRight' respectively
        vector<vector<int>>ans;
        for(int i=topLeft[0];i<=bottomRight[0];i++) {
            vector<int>tmp;
            for(int j=topLeft[1];j<=bottomRight[1];j++) {
                tmp.push_back(a[i][j]);
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
