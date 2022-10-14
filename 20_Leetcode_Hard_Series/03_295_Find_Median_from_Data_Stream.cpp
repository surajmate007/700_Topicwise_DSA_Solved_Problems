// the important point to note is we first check whether mxh.empty() or mxh.top() >= num. Then only we push element in maxheap. Else we push it in minheap.
// While balancing mxh.size() > mnh.size()+1 then shift or mnh.size() > mxh.size() then also shift.


class MedianFinder {
public:
    priority_queue<int> mxh;
    priority_queue<int, vector<int>, greater<int>> mnh;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(mxh.size()==0 or mxh.top()>=num){
            mxh.push(num);
        }
        else{
            mnh.push(num);
        }

        if(mxh.size() > mnh.size()+1){
            mnh.push(mxh.top());
            mxh.pop();
        }
        else if(mnh.size() > mxh.size()){
            mxh.push(mnh.top());
            mnh.pop();
        }
    }
    
    double findMedian() {
        if(mxh.size() == mnh.size()){
            return (mxh.top()+mnh.top())/(double)2.0;
        }
        else{
            return (double)mxh.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
