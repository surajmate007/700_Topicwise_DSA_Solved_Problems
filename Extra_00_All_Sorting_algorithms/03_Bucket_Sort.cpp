#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;


void bucketSort(int arr[], int n){
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        mx = max(mx, arr[i]);
    }
    int s = sqrt(n);

    vector<vector<int> > bucket(n);
    for(int i=0; i<n; i++){
        int bn = ceil(((double)arr[i]*(double)s)/(double)mx);
        bucket[bn-1].push_back(arr[i]);
    }

    int p=0;
    for(int i=0; i<bucket.size(); i++){
         
        sort(bucket[i].begin(), bucket[i].end());
        for(int j=0; j<bucket[i].size(); j++){
            arr[p] = bucket[i][j];
            p++;
        }
    }
}

int main(){
    int arr[] = {7, 3, 4, 9, 23, 45, 11, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bucketSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
