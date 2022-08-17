// Here the question is can we sort the arrauy in increasing order when we can only swap the adjacent elements if they have different strenghts.
// The strengths of the elements is defined as thre min power of 2 the element can have. ie 2^n <= element, then n will be its strength.

int getStrength(int n){
    int last = n;
    while(n != 0){
        last = n;
        n = n & (n-1);
    }
    return last;
}

int Solution::solve(vector<int> &arr) {
    int n = arr.size();
    vector<int> strength;
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++){
        int val = getStrength(arr[i]);
        if(mp.find(val) == mp.end()){
            mp[val] = arr[i];
        }
        else{
            if(mp[val] <= arr[i]){
                mp[val] = arr[i];
            }
            else{
                return 0;
            }
        }
    }
    
    return 1;
}
