/*
    simple iteration
    TC: O(N)
*/
vector<int> find(int arr[], int n, int x)
{
    // code here
    int i = n, j = 0;
    bool flag = true;
    for (int k = 0;k < n;k++) {
        if (arr[k] == x) {
            i = min(i, k);
            j = max(j, k);
            flag = false;
        }
    }

    // if ele is not present
    if (flag) return { -1, -1 };

    // if ele is present
    return { i, j };
}



/*
    using binary search
    TC: O(logn)
    SC: O(1)
*/ 

// Important points to note:
// 1. For first occurance of an element in else part we have to do hi = mid-1;
// 2. For last occurance of an element in lese part we have to do lo = mid+1;

// lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 
// and if the value is not present in the vector then it returns the end iterator.
// upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 
                                                                            
                                                                            
vector<int> find(int arr[], int n, int x){
    int lo=0; int hi=n-1; vector<int> ans;

    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] < x){
           lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    ans.push_back(lo);
    
    lo = 0; hi=n-1;
    
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] > x){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    
    if(hi < ans.back()){
        ans.pop_back();
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else{
        ans.push_back(hi);
    }
    return ans;
}
