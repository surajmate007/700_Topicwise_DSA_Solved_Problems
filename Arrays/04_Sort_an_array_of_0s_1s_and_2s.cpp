// using 3 pointer method where the middle pointer will always look for maintaining 0 below its index and 2 above its index.

void sort012(int a[], int n){
    int p=0; int q=0; int r=n-1;
    while(q <= r){
        int temp;
        if(a[q] == 0){
            temp = a[p];
            a[p] = a[q];
            a[q] = temp;
            p++; q++;
        }
        else if (a[q] == 1){
            q++;
        }
        else{
            temp = a[r];
            a[r] = a[q];
            a[q] = temp;
            r--;
        }
    }
}
