// Here we are first sorting the array and then arranging the bigger ekements in between smaller elements and then finding the answer.

long long int maxSum(int arr[], int n){
    sort(arr, arr+n);
    int i=0; int j=n-1;

    vector<int> vec;
    
    while(i <= j){
        vec.push_back(arr[i]);
        vec.push_back(arr[j]);
        i++; j--;
    }
  
    long long int ans = 0;
    for(int i=0; i<n-1; i++){
        ans += abs(vec[i] - vec[i+1]);
    }
    ans += abs(vec[0] - vec[n-1]);
    
    return ans;
}
