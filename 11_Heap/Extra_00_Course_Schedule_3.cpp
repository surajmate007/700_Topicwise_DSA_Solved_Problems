// Solution using priority queue.


class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int n = courses.size();
        
        priority_queue<int> pq;
        int sum = 0;
        
        for(auto e : courses){
            sum += e[0];
            pq.push(e[0]);
            if(sum > e[1]){
                sum -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
        
    }
};
