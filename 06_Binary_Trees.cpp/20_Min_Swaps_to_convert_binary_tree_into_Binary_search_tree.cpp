// for binary search tree the inorder traversal should be sorted.
// Hence we will first craete the inorder traversal of the given tree and then using
// the method of minimum number of swaps required to sort the the array.

int minSwaps(vector<int>&nums){
	    int n = nums.size();
	    vector<int> vec(nums.begin(), nums.end());
	    sort(nums.begin(), nums.end());
	    unordered_map<int, int> mp;
	    for(int i=0; i<n; i++){
	        mp[vec[i]] = i;
	    }
	    int ans = 0;
	    for(int i=0; i<n; i++){
	        int temp1 = vec[i]; int temp2 = nums[i];
	        swap(vec[mp[temp1]], vec[mp[temp2]]);
	        swap(mp[temp1], mp[temp2]);
	        if(temp1 != temp2){
	            ans ++;
	        }
	    }
	    
	    return ans;
	}


// Recursive function to perform inorder traversal on the tree
vector<int> vce;
void inorder(Node* root){
    // return if the current node is empty
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    inorder(root->left);

    // Display the data part of the root (or current node)
    vec.push_back(root->data);

    // Traverse the right subtree
    inorder(root->right);
}


int toBST(Node* root){
  inorder(root);
  int ans = minSwaps(vec);
  
  return ans;
}
  
