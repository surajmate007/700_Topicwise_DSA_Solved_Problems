// for kth smallest element we use maxheap(priority queue) and for kth largest element we use minheap.

int kthSmallest(int arr[], int l, int r, int k){
        priority_queue<int> pq;
        for(int i=0; i<=r; i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
}



// for kth largest elemengt we can implement minheap as below:

int kthLargest(int arr[], int l, int r, int k){
        priority_queue <int, vector<int>, greater<int> > pq;            // this line will create minheap.
        for(int i=0; i<=r; i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
}
