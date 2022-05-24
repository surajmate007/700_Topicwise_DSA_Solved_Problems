// we can loop through elements and in each loop we will subtract the number from the given target.
// after fixing the 2 elements we will then find the remaining 2 elements by using the 2 pointer approach.
// for that we will firt need to sort the array.
// TC = O(n3)

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        set<vector<int>> st; int n = arr.size();
        for(int i=0; i<n; i++){
            int dif1 = k-arr[i];
            for(int j=i+1; j<n; j++){
                int dif2 = dif1-arr[j];
                int p=j+1; int q=n-1;
                while(p < q){
                    int sum = arr[p] + arr[q];
                    if(sum == dif2){
                        vector<int> vec;
                        vec.push_back(arr[i]);
                        vec.push_back(arr[j]);
                        vec.push_back(arr[p]);
                        vec.push_back(arr[q]);
                        st.insert(vec);
                        p++; q--;
                    }
                    else if(sum < dif2){
                        p++;
                    }
                    else{
                        q--;
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        
        return ans;
    }
};
