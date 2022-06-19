// Thi sis the somplest code using recursion for reversing thw queue.

void getAns(queue<int>& q){
    if(q.empty()){
        return;
    }
    
    
    int a = q.front();
    q.pop();
    getAns(q);
    q.push(a);
}

queue<int> rev(queue<int> q){
    getAns(q);
    
    return q;
}
