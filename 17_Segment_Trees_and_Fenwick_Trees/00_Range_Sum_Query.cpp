// solved using segment trees.
// build, update and query are the important functions for segment trees.

class NumArray {
public:
    int size = 0;
    vector<int> nseg;
    
    void build(int ind, int lo, int hi, vector<int>& arr, vector<int>& seg){
        if(lo == hi){
            seg[ind] = arr[lo];
            return;
        }
        
        int mid = (lo + hi)/2;
        build(2*ind+1, lo, mid, arr, seg);
        build(2*ind+2, mid+1, hi, arr, seg);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
    void update(int ind, int lo, int hi, int i, int val, vector<int>& seg){
        if(lo == hi){
            seg[ind] = val;
            return;
        }
        
        int mid = (lo + hi)/2;
        if(i <= mid){
            update(2*ind+1, lo, mid, i, val, seg);
        }
        else{
            update(2*ind+2, mid+1, hi, i, val, seg);
        }
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
    int query(int ind, int lo, int hi, int left, int right, vector<int>& seg){
        if(left > hi or right < lo){
            return 0;
        }
        else if(left <= lo and right >= hi){
            return seg[ind];
        }
        
        int mid = (lo + hi) >> 1;
        
        int left_val = query(2*ind+1, lo, mid, left, right, seg);
        int right_val = query(2*ind+2, mid+1, hi, left, right, seg);
        
        return left_val + right_val;
    }
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> seg(4*n);
        size = n;
        build(0, 0, n-1, nums, seg);
        nseg = seg;
    }
    
    void update(int index, int val) {
        update(0, 0, size-1, index, val, nseg);
    }
    
    int sumRange(int left, int right) {
        int ans = query(0, 0, size-1, left, right, nseg);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
