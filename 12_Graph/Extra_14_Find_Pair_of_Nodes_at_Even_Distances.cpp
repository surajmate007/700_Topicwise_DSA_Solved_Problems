// Approach:  

// Assume a graph is having 6 levels (0 to 5) level 0, 2, 4 are at even distance but level 1, 3, 5 are also at even distance as their difference is 2 which
// is even so we have to take care of both the conditions i.e count both levels even and odd.
// The given problem can be solved by performing dfs traversal
// Choose any source node as root and perform dfs traversal and maintain the visited 
// array for performing dfs and dist array to calculate distance from the root
// now traverse the distance array and keep count of even level and odd level
// Calculate total as ((even_count * (even_count-1)) + (odd_count * (odd_count-1))/2

// C++ program to find
// the count of nodes
// at even distance
#include <bits/stdc++.h>
using namespace std;

// Dfs function to find count of nodes at
// even distance
void dfs(vector<int> graph[], int node, int dist[],
									bool vis[], int c)
{
	if (vis[node]) {
		return;
	}
	// Set flag as true for current
	// node in visited array
	vis[node] = true;

	// Insert the distance in
	// dist array for current
	// visited node u
	dist[node] = c;

	for (int i = 0; i < graph[node].size(); i++) {
		// If its neighbours are not vis,
		// run dfs for them
		if (!vis[graph[node][i]]) {
			dfs(graph, graph[node][i], dist, vis, c + 1);
		}
	}
}

int countOfNodes(vector<int> graph[], int n)
{
	// bool array to
	// mark visited nodes
	bool vis[n + 1] = { false };

	// Integer array to
	// compute distance
	int dist[n + 1] = { 0 };

	dfs(graph, 1, dist, vis, 0);

	int even = 0, odd = 0;

	// Traverse the distance array
	// and count the even and odd levels
	for (int i = 1; i <= n; i++) {
		if (dist[i] % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}

	int ans = ((even * (even - 1)) + (odd * (odd - 1))) / 2;

	return ans;
}

// Driver code
int main()
{

	int n = 5;
	vector<int> graph[n + 1] = { {},
								{ 2 },
								{ 1, 3 },
								{ 2 } };

	int ans = countOfNodes(graph, n);
	cout << ans << endl;

	return 0;
}
