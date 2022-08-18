// easy solution check greedily.

int Solution::maxArea(vector<int> &arr) {
    int n = arr.size();
    int left=0; int right=n-1;
    int ans = 0; int area = 0;
    
    while(left <= right){
        area = (right-left) * min(arr[right], arr[left]);
        ans = max(ans, area);
        if(arr[right] < arr[left]){
            right--;
        }
        else{
            left++;
        }
    }
    
    return ans;
}
