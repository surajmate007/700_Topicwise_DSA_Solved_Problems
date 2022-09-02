// solution using pq.

class Solution {
public:
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = heights.size();
        int brickSum = 0;
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if(diff <= 0) continue;
            
            pq.push(diff);
            if(pq.size() > ladders) {
                brickSum += pq.top();
                pq.pop();
            }   
            if(brickSum > bricks) return i - 1;
        }
        return n-1;  
    }
};

// Uisng backtracking but giving TLE.

    void getAns(vector<int> a, int n, int idx, int b, int l, int& ans){
        if(idx == n-1){
            ans = max(ans, n-1);
            return;
        }
        
          
        if(a[idx+1] > a[idx] and l==0 and b < (a[idx+1] - a[idx])){
            ans = max(ans, idx);
            return;
        }
        
        if(a[idx+1] <= a[idx]){
            getAns(a, n, idx+1, b, l, ans);
        }
        
        else{
            int dif = a[idx+1] - a[idx];
            
            if(b >= dif){
                getAns(a, n, idx+1, b-dif, l, ans);
            }
            
            if(l > 0){
                getAns(a, n, idx+1, b, l-1, ans);
            }
        }
    }
