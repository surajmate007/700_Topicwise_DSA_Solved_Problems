// we will first sort the array and then compare it with given original array.
// We will store the indexes of elements into the map from the original array.
// then we will swap th elements in the oorigianl arrays and also swap the indexes of elements in the map.

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



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    here we r trying to make sorted vector to original array (reversed way!)
    Time Complexity: O(n Log n).
    Auxiliary Space: O(n).
*/
// C++ program to find the minimum number
// of swaps required to sort an array
// of distinct element

#include<bits/stdc++.h>
using namespace std;

// Function to find minimum swaps to
// sort an array
int findMinSwap(int arr[], int n)
{
    // Declare a vector of pair	
    vector<pair<int, int>> vec(n);

    for (int i = 0;i < n;i++)
    {
        vec[i].first = arr[i];
        vec[i].second = i;
    }

    // Sort the vector w.r.t the first
    // element of pair
    sort(vec.begin(), vec.end());

    int ans = 0, c = 0, j;

    for (int i = 0;i < n;i++)
    {
        // If the element is already placed
        // correct, then continue
        if (vec[i].second == i)
            continue;
        else
        {
            // swap with its respective index
            swap(vec[i].first, vec[vec[i].second].first);
            swap(vec[i].second, vec[vec[i].second].second);
        }

        // swap until the correct
        // index matches
        if (i != vec[i].second)
            --i;

        // each swap makes one element
        // move to its correct index,
        // so increment answer
        ans++;
    }

    return ans;
}

// Driver code
int main()
{
    int arr[] = { 1, 5, 4, 3, 2 };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findMinSwap(arr, n);

    return 0;
}
