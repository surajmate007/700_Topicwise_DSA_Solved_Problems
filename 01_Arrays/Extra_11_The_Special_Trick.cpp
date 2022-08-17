// Here we have to find minimum seperate intervals in which all intervals can be included.

static bool comp(pair<int, int>& a, pair<int, int>& b){
    return a.first < b.first;
}

int Solution::solve(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<pair<int, int>> vec;
    for(int i=0; i<n; i++){
        vec.push_back({start[i], end[i]});
    }
    
    sort(vec.begin(), vec.end(), comp);
    int ans = 1;
    
    int last = vec[0].second;
    for(int i=0; i<n; i++){
        if(vec[i].first <= last){
            last = min(last, vec[i].second);
        }
        else{
            ans++;
            last = vec[i].second;
        }
    }
    
    return ans;
}
