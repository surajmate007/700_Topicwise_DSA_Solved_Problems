// Important problem asked in many interviews.

int Solution::canCompleteCircuit(const vector<int> &fuel, const vector<int> &cost) {
    int n = fuel.size();
    vector<int> diff;
    for(int i=0; i<n; i++){
        diff.push_back(fuel[i] - cost[i]);
    }
    
    for(int i=0; i<n; i++){
        if(diff[i] >= 0){
            int sum = 0;
            for(int j=i; j<=i+n; j++){
                sum += diff[j%n];
                if(sum < 0){
                    break;
                }
            }
            if(sum >= 0){
                return i;
            }
        }
    }
    
    return -1;
}
