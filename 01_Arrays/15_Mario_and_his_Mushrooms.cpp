// problem Link : https://www.interviewbit.com/test/422a85c4d2/?signature=BAhpA1R%2BFA%3D%3D--6b6355376806bf1330bf3216b137722866f49584#/problem_2

int Solution::maximumMushrooms(vector<vector<int> > &arr) {
    map<int, vector<int>> mp;
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        mp[arr[i][0]].push_back(arr[i][1]);
    }
    
    int curr = 1; int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    while(1){
        while(!pq.empty() and pq.top() < curr){
            pq.pop();
        }
        
        if(mp.size()!=0 and mp.begin()->first == curr){
            vector<int> vec = mp.begin()->second;
            for(int i=0; i<vec.size(); i++){
                pq.push(vec[i]);
            }
            mp.erase(mp.begin()->first);
        }
        
        if(!pq.empty()){
            pq.pop(); ans++; curr++;
        }
        
        if(pq.empty()){
            if(mp.size() == 0){
                break;
            }
            curr = mp.begin()->first;
        }
        
    }
    return ans;
}
