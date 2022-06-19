// This is simple brute force approach for this probelm.

queue<int> modifyQueue(queue<int> q, int k) {
    int n = q.size(); vector<int> vec;
    while(k--){
        vec.push_back(q.front());
        q.pop();
    }
    
    reverse(vec.begin(), vec.end());
    while(!q.empty()){
        vec.push_back(q.front());
        q.pop();
    }
    
    for(int i=0; i<n; i++){
        q.push(vec[i]);
    }
    
    return q;
}
