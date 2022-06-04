// Code written by me.
// I am using unordered_map to store the last index of each element in the given first array.
// Then we are traversing over the array and find last index of the top element in the satck and then we move uptot his index and check
// all the elements are in their correct position or not.


class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int, int> mp;
        for(int i=0; i<2*e; i++){
            mp[A[i]] = i;
        }
        
        int i=0;
        stack<int> st;
        st.push(A[0]);
        
        while(i < 2*e){
            int t = st.top();
            int j = mp[t]+1;
            while(j<=i){
                st.pop();
                t = st.top();
                j = mp[t]+1;
            }
            
            while(i <= mp[t]+1){
                if(A[i+1] == B[j] and B[i+1] == A[j]){
                    st.push(A[i]); st.push(A[i+1]);
                    i+=2; j-=2;
                }
                else{
                    return 0;
                }
            }
        }
        
        return 1;
    }
};




// Another approach from GFG. But this problem has 2 seperate arrays.

// C++ program to check if two n-ary trees are
// mirror.
#include <bits/stdc++.h>
using namespace std;

// Function to check given two trees are mirror
// of each other or not
int checkMirrorTree(int M, int N, int u1[ ],
					int v1[ ] , int u2[], int v2[])
	{
		// Map to store nodes of the tree
		unordered_map<int , stack<int>>mp;

		// Traverse first tree nodes
		for (int i = 0 ; i < N ; i++ )
		{
		mp[u1[i]].push(v1[i]);
		}
		
		// Traverse second tree nodes
		for (int i = 0 ; i < N ; i++)
		{
			if(mp[u2[i]].top() != v2[i])
				return 0;
			mp[u2[i]].pop();
		}

		return 1;
	}

// Driver code
int main()
{
	int M = 7, N = 6;
	
	//Tree 1
	int u1[] = { 1, 1, 1, 10, 10, 10 };
	int v1[] = { 10, 7, 3, 4, 5, 6 };

	//Tree 2
	int u2[] = { 1, 1, 1, 10, 10, 10 };
	int v2[] = { 3, 7, 10, 6, 5, 4 };

	if(checkMirrorTree(M, N, u1, v1, u2, v2))
	cout<<"Yes";
	else
	cout<<"No";

	return 0;
}

