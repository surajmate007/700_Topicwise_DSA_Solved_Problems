// since all the digits are same and we hav eto find the next greater number hence it is nothing but next permutation problem.

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int idx1 = -1, idx2 = -1;
        for(int i=N-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                idx1 = i; break;
            }
        }
        
        if(idx1 == -1){
            reverse(arr.begin(), arr.end());
            return arr;
        }
        
        for(int i=N-1; i>=0; i--){
            if(arr[i] > arr[idx1]){
                idx2 = i; break;
            }
        }
        swap(arr[idx1], arr[idx2]);
        reverse(arr.begin()+idx1+1, arr.end());
        return arr;
    }
};

// More easier approach using the inbuilt funtion next_permutation:

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        next_permutation(arr.begin(), arr.end());
        return arr;
    }
};
