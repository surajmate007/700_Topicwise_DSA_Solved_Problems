// using hashing:

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int t = nums.size()/3;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto ele : mp){
            if(ele.second > t){
                ans.push_back(ele.first);
            }
        }
        return ans;
    }
};

// using logic that there can be no more than 2 n/k frequent elements from mathematics. 
// hence we will first find 2 most frequent elements and then we will check whether these frequent elements are appearing more than n/k times:

// called : MOORE VOTING ALGORITHM

vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = floor(nums.size()/3);
        int ele1 = -1, ele2 = -1;
        int cnt1 = 0, cnt2 = 0;
        for(int ele : nums){
            if(ele == ele1){
                cnt1++;
            }
            else if(ele == ele2){
                cnt2++;
            }
            else if(cnt1 == 0){
                ele1 = ele;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                ele2 = ele;
                cnt2 = 1;
            }
            else{
                cnt1 --; cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;
        for(int ele : nums){
            if(ele == ele1){
                cnt1++;
            }
            if(ele == ele2){
                cnt2++;
            }
        }
        
        if(cnt1 > n){
            ans.push_back(ele1);
        }
        if(cnt2 > n){
            if(ele2 != ele1){
                ans.push_back(ele2);   
            }
        }
        return ans;
    }
