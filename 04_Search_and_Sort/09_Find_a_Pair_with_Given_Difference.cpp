// Brute force with O(n^2) complexity:

bool findPair(int arr[], int size, int n){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(abs(arr[i] - arr[j]) == n){
                return true;
            }
        }
    }
    return false;
}

// First sort the array and then implement 2 pointer approach both starting from index 0:
// TC = O(nlogn)

bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    int i=0; int j=1;
    while(j<size and i<size){
        int dif = arr[j]-arr[i];
        if(dif == n and i!=j){
            return true;
        }
        else if(dif > n){
            i++;
        }
        else{
            j++;
        }
    }
    return false;
}

// using O(n) time and extra O(n) space:

bool findPair(int arr[], int size, int n){
    unordered_map<int, int> mp;
    for(int i=0; i<size; i++){
        if(mp.find(arr[i]+n) != mp.end() or mp.find(arr[i]-n) != mp.end()){
            return true;
        }
        mp[arr[i]]++;
    }
    
    return false;
}
