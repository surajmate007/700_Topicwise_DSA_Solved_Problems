
class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        string ans = "";
        int carry = 0;
        int sum = 0;
        
        for(int i=n-1;i>=0;i-=2){
            sum = arr[i] + arr[i-1];
            if(sum == 0 && carry == 0)
            return ans;
            ans = to_string((sum+carry)%10) + ans;
            carry = (sum+carry)/10;
        }
        
        if(carry>0)
        ans = to_string(carry) + ans;
        return ans;
    }
};
