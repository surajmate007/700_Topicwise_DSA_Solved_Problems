// using 3 pointer method where the middle pointer will always look for maintaining 0 below its index and 2 above its index.

void sort012(int a[], int n){
    int p=0; int q=0; int r=n-1;
    while(q <= r){
        int temp;
        if(a[q] == 0){
            swap(a[p], a[q]);
            p++; q++;
        }
        else if (a[q] == 1){
            q++;
        }
        else{
            swap(a[r], a[q]);
            r--;
        }
    }
} 

// we can also use another simple method which takes O(n) space where we count number of 0s, 1s and 2s and then run a loop and fill the array with 
// corresponding number of elements.
