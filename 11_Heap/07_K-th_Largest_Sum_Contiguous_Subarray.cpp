// A brute force approach is to store all the contiguous sums in another array and sort it and print the k-th largest. But in the case of the number of
// elements being large, the array in which we store the contiguous sums will run out of memory as the number of contiguous subarrays will be large
// (quadratic order)
// An efficient approach is to store the pre-sum of the array in a sum[] array. We can find sum of contiguous subarray from index i to j as sum[j]-sum[i-1] 
// Now for storing the Kth largest sum, use a min heap (priority queue) in which we push the contiguous sums till we get K elements, once we have our K
// elements, check if the element is greater than the Kth element it is inserted to the min heap with popping out the top element in the min-heap,
// else not inserted. In the end, the top element in the min-heap will be your answer.


class Solution{
public:
    int kthLargest(vector<int> &a,int n,int k){
        int sum [n+1];
        sum[0] = 0; sum[1] = a[0];
        
        for(int i=2; i<=n; i++){
            sum[i] = sum[i-1] + a[i-1];
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                int x = sum[j] - sum[i-1];
                
                if(pq.size() < k){
                    pq.push(x);
                }
                else{
                    if(pq.top() < x){
                        pq.pop();
                        pq.push(x);
                    }
                }
            }
        }
        
        return pq.top();
    }
};
