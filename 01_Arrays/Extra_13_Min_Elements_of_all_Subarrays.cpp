// Approach: The Naive approach is to generate all possible (contiguous) subarrays, find their minimum and add them to result. 
// The time complexity will be O(N2).
// Efficient Approach: The general intuition for solution to the problem is to find sum(A[i] * f(i)), where f(i) is the number of subarrays in which
// A[i] is the minimum.
// In order to find f[i], we need to find out: 
// left[i], the length of strictly larger numbers on the left of A[i], 
// right[i], the length of larger numbers on the right of A[i].
// We make two arrays left[ ] and right[ ] such that: 
// left[i] + 1 equals to the number of subarrays ending with A[i], and A[i] is only single minimum. 
// Similarly, right[i] + 1 equals to the number of subarrays starting with A[i], and A[i] is first minimum.
// Finally, f(i) = (left[i]) * (right[i]), where f[i] equals total number of subarrays in which A[i] is minimum.x
// Below is the implementation of above approach 

// simple approach using dq:
// solved in coding ninjas contest.

#include <bits/stdc++.h> 
long long int superScore(int n, vector<int> arr) {
    vector<int> left(n), right(n);
    deque<int> dq;
    
    for(int i=0; i<n; i++){
        if(dq.empty()){
            left[i] = i+1;
        }
        else{
            while(!dq.empty() and arr[dq.back()] > arr[i]){
                dq.pop_back();
            }
            if(dq.empty()){
                left[i] = i+1;
            }
            else{
                left[i] = i-dq.back();
            }
        }
        dq.push_back(i);
    }
    
    dq.clear();
    
    for(int i=n-1; i>=0; i--){
        if(dq.empty()){
            right[i] = n-i;
        }
        else{
            while(!dq.empty() and arr[dq.back()] >= arr[i]){
                dq.pop_back();
            }
            if(dq.empty()){
                right[i] = n-i;
            }
            else{
                right[i] = dq.back()-i;
            }
        }
        dq.push_back(i);
    }
    
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += (1ll * arr[i] * 1ll * arr[i] * 1ll * left[i] * 1ll * right[i]);
    }
    
    return ans;
}


// CPP implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// Function to return required minimum sum
int sumSubarrayMins(int A[], int n)
{
	int left[n], right[n];

	stack<pair<int, int> > s1, s2;

	// getting number of element strictly larger
	// than A[i] on Left.
	for (int i = 0; i < n; ++i) {
		int cnt = 1;

		// get elements from stack until element
		// greater than A[i] found
		while (!s1.empty() && (s1.top().first) > A[i]) {
			cnt += s1.top().second;
			s1.pop();
		}

		s1.push({ A[i], cnt });
		left[i] = cnt;
	}

	// getting number of element larger than A[i] on Right.
	for (int i = n - 1; i >= 0; --i) {
		int cnt = 1;

		// get elements from stack until element greater
		// or equal to A[i] found
		while (!s2.empty() && (s2.top().first) >= A[i]) {
			cnt += s2.top().second;
			s2.pop();
		}

		s2.push({ A[i], cnt });
		right[i] = cnt;
	}

	int result = 0;

	// calculating required resultult
	for (int i = 0; i < n; ++i)
		result = (result + A[i] * left[i] * right[i]);

	return result;
}

// Driver program
int main()
{
	int A[] = { 3, 1, 2, 4 };

	int n = sizeof(A) / sizeof(A[0]);

	// function call to get required resultult
	cout << sumSubarrayMins(A, n);

	return 0;
}
