// This is the solution using bit manipulation.
// The algorithm is little bit complex.
// Since we know XOR of 2 equal numbers is 0. Hence we are calculating the xor of complete array elements and then we are finding the first set bit from 
// right in the overall XOR. If set bit is persent in overall XOR means one of the bi is set. Then we are seperating the numbers into 2 sets one having
// set bit at this position and other not having set bit at this position.
// After seperating the numbers we will take XOR of these numbers and the reselt of these seperate groups will be the numbers whicg are not repeated.


class Solution{
  public:
    vector<int> singleNumber(vector<int> nums) {
        vector<int> ans; int n = nums.size();
        int XOR = nums[0];
        
        for(int i=1; i<n; i++){
            XOR = XOR ^ nums[i];
        }
        int right_bit = XOR & ~(XOR-1);
        int x=0, y=0;
        
        for(int i=0; i<n; i++){
            if(nums[i] & right_bit){
                x = x^ nums[i];
            }
            else{
                y = y ^ nums[i];
            }
        }
        
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
