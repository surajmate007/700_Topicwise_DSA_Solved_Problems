// Simple solution using priority queue.

class Solution{
  public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(long long i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        long long  ans = 0;
        while(pq.size() > 1){
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            long long sum = a + b;
            ans += sum;
            pq.push(sum);
        }
        
        return ans;
    }
};
