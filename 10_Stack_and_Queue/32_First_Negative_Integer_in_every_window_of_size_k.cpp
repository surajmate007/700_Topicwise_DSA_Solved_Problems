// This is the simple approach using queue where we are storing elements intot the queue and then popoing then until we get the negative element.

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
    vector<long long> ans;
    queue<long long > q;
    for(int i=0; i<k; i++){
        q.push(a[i]);
    }
    
    for(int i=0; (i+k-1)<n; i++){
        while(!q.empty() and q.front() > 0){
            q.pop();
        }
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(q.front());
        }
        
        q.push(a[k+i]);
        if(q.size() > k){
            q.pop();
        }
    }
    
    return ans;
}
