// we will be using easy approach :
// first we are using BRIAN KERNINGAM'S Algorithm for finding the number of set bits in binary representation of any number.
// Then we will store number and its count of set bits as a pair in vector.
// Then we will stable sort this vector according to count of set bits using comparator and stable_sort function in library.
// After that we will clear the original array and fill it with elementds from the sorted vector.


class Solution{
    public:
  
    int setBits(int n){       // BRIAN KERNINGAM'S Algorithm for finding the number of set bits.
        int res = 0;
        while(n > 0){
            n = n&(n-1);
            res++;
        }
        return res;
    }
    
    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
    
    void sortBySetBitCount(int arr[], int n){
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({arr[i], setBits(arr[i])});
        }
        
        stable_sort(vec.begin(), vec.end(), comp);
        
        fill(arr, arr+n, 0);
        int i=0;
        for(auto e : vec){
            arr[i] = e.first;
            i++;
        }
    }
};
