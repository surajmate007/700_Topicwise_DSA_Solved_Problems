// Simple approach using 2 heaps one is maxheap and another is minheap.
// elements greater than median are stored in the minheap and elements lesser than median are stored in the maxheap.
// When the size of heaps are same then this ios the even case where median is the avegare of the top elements in both the heaps.
// When the size is different then the median is present at the top of the maxheap.


class Solution{
  public:
    //Function to insert heap.
    priority_queue<double> maxheap;
    priority_queue<double, vector<double>, greater<double>> minheap;
    
    void insertHeap(int &x){
        if(maxheap.size() == 0 or maxheap.top() >= x){
            maxheap.push((double)x);
        }
        else{
            minheap.push((double)x);
        }
        
        balanceHeaps();
    }
    
    
    void balanceHeaps(){
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    
    double getMedian(){
        if(maxheap.size() == minheap.size()){
            return (maxheap.top() + minheap.top())/2;
        }
        
        return maxheap.top();
    }
};
