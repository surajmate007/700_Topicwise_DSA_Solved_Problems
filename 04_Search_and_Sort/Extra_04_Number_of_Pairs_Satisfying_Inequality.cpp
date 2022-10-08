// simple merge sort based approach:

class Solution {
public:

    long long merge(vector<int>& arr, int lo, int mid, int hi, int diff){
        int i = lo; int j = mid+1;
        long long ans = 0;

        while(i<=mid and j<=hi){
            if(arr[i] - arr[j] <= diff){
                ans += (hi-j+1);
                i++;
            }
            else{
                j++;
            }
        }
        sort(arr.begin()+lo, arr.begin()+hi+1);
        return ans;
    }

    long long mergeSort(vector<int>& arr, int lo, int hi, int diff){
        long long ans = 0;

        if(lo < hi){
            int mid = (lo + hi)>>1;
            ans += mergeSort(arr, lo, mid, diff);
            ans += mergeSort(arr, mid+1, hi, diff);
            ans += merge(arr, lo, mid, hi, diff);
        }

        return ans;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> nums;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            nums.push_back(nums1[i] - nums2[i]);
        }
        long long ans = mergeSort(nums, 0, n-1, diff);
        return ans;
    }
};
