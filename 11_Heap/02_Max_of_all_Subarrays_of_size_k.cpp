// We are simply using the double ended queue wherre we are pushing the elements from the rear and always trying to maintain the decreasing order of
// elements inside the queue.
// The front element inside the queue will always show the max element inside the window under cionsideration.
// We are poping the elements from the queue when the index goes out of the window indexes.

class Solution{
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans; int mx = 0;
        deque<int> q;

        for(int i=0; i<k; i++){
            if(q.empty()){
                q.push_back(i);
            }
            else{
                while(!q.empty() and arr[q.back()] < arr[i]){
                    q.pop_back();
                }
                q.push_back(i);
            }
        }
        
        ans.push_back(arr[q.front()]);
        
        for(int i=k; i<n; i++){
            
            if(q.empty()){
                q.push_back(i);
            }
            else{
                while(!q.empty() and arr[q.back()] < arr[i]){
                    q.pop_back();
                }
                q.push_back(i);
            }
            
            if(q.front() <= i-k){
                q.pop_front();
            }
            
            ans.push_back(arr[q.front()]);
        }
        
        return ans;
    }
};
