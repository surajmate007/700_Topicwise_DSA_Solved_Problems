// Uisng deque.
// we are inly inserting the maximum element and while inserting new element into the queue we are checking whether the element at the end of the queue
// is smaller than the element we are going to insert if it is then we will pop back all such smaller elements from the queue.



#include<bits/stdc++.h>
using namespace std;

vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();

    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
