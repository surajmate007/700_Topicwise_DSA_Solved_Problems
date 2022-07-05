int minCashFlow(vector<vector<int>>& money, int n){
    vector<int> khatabook(n,0); //ultimately the stores the credit and debit.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            khatabook[i] -= money[i][j]; // from person i, money is taken out so it is subtracted
            khatabook[j] += money[i][j]; // from person i, money is received to person j so added in vector of j
            }
        }
    
    
    int sum=0;
    for(int i=0;i<n;i++){
          if(khatabook[i]>0){  // so add the credits / debits its gonna be the same.
                sum+=khatabook[i]; 
          }
    }
    
    return sum;
}
