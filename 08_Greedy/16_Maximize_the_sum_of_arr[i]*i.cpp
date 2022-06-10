// We are first sorting the array and then finding the product.

int Maximize(int a[],int n){
       int m = 1e9 + 7;
       sort(a, a+n);
       long long int product = 0;
       for(int i=0; i<n; i++) {
           product = product + ((long long int)a[i]*i);
           product = product % m;
       }
       return product;
   }
};
