// simply using hashmap


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[a1[i]]++;
    }
    for(int i=0; i<m; i++){
        if(mp.find(a2[i]) == mp.end()){
            return "No";
        }
    }
    return "Yes";
}
