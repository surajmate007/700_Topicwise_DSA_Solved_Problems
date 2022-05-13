// first storing all positive elements in one array and all negative elements in other array and then replacing elements in original array 
// according to the required order.
// we are doing this because we need to maintain the order of elements.

void segregateElements(int a[],int n){
        vector<int> vec;
        for(int i=0; i<n; i++){
            if(a[i] > 0){
                vec.push_back(a[i]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(a[i] < 0){
                vec.push_back(a[i]);
            }
        }
        
        for(int i=0; i<n; i++){
            a[i] = vec[i];
        }
    }


// if we dont need to maintain the order of elements then we can simply sort the array and use 2 pointer approach where one is staerting from +ve and 
// other from -ve.
