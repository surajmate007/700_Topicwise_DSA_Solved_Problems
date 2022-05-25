// easy solution:
// Based on frequency of corresponding characters we are differeatiating the two strings.

class Solution{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2){
        int n = str1.size(); int m = str2.size();
        if(n != m){
            return false;
        }
        int arr1[256] = {0};
        int arr2[256] = {0};
        
        for(int i=0; i<n; i++){
            arr1[str1[i]]++;
            arr2[str2[i]]++;
        }
        
        for(int i=0; i<m; i++){
            if(arr1[str1[i]] != arr2[str2[i]]){
                return false;
            }
        }
        
        return true;
    }
};
