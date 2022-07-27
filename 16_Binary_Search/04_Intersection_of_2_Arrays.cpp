class Solution {
public:
    
    int serachElement(vector<int> vec, int n, int tar){
        int lo = 0; int hi = n-1;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(vec[mid] == tar){
                return tar;
            }
            else if(vec[mid] < tar){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        
        return -1;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> ans;
        set<int> st;
        for(int i=0; i<nums2.size(); i++){
            st.insert(nums2[i]);
        }
        
        for(auto e : st){
            if(serachElement(nums1, n, e) != -1){
                ans.push_back(e);
            }
        }
        
        return ans;
    }
};
