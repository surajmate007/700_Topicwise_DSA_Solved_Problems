// if we need to maintain the order of elements in the array. then we need O(n) extra space. 
void rearrange(int arr[], int n) {
	    vector<int>neg; vector<int> pos;
	    for(int i=0; i<n; i++){
	        if(arr[i] >= 0){
	            pos.push_back(arr[i]);
	        }
	        else{
	            neg.push_back(arr[i]);
	        }
	    }
	    int i=0; int j=0; int p=0;
	    while(i<pos.size() and j<neg.size()){
	        if(p%2==0){
	            arr[p] = pos[i];
	            i++; 
	        }
	        else{
	            arr[p] = neg[j];
	            j++;
	        }
	        p++;
	    }
	    while(i < pos.size()){
	        arr[p] = pos[i];
	        p++; i++;
	    }
	    while(j < neg.size()){
	        arr[p] = neg[j];
	        p++; j++;
	    }
	}


// if we dont need to maintain the order of elements in the array then we can simply sort the array first and then
// starting one pointer from +ve and other from -ve elements and swaping the elements in proper order. 
