// Better explained with figures : https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/

// Travelling Salesman Problem (TSP): 
// Given a set of cities and the distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly
// once and returns to the starting point. Note the difference between Hamiltonian Cycle and TSP. The Hamiltonian cycle problem is to find if there exists
// a tour that visits every city exactly once. Here we know that Hamiltonian Tour exists (because the graph is complete) and in fact, many such tours exist,
// the problem is to find a minimum weight Hamiltonian Cycle. 

// For example, consider the graph shown in the figure on the right side. A TSP tour in the graph is 1-2-4-3-1. The cost of the tour is 10+25+30+15
// which is 80. The problem is a famous NP-hard problem. There is no polynomial-time know solution for this problem. The following are different solutions
// for the traveling salesman problem.

// 1) Consider city 1 as the starting and ending point.
// 2) Generate all (n-1)! Permutations of cities. 
// 3) Calculate the cost of every permutation and keep track of the minimum cost permutation. 
// 4) Return the permutation with minimum cost. 
// Time Complexity: Θ(n!) 


// DP approach is better explained here : https://www.youtube.com/watch?v=XaXsJJh-Q5Y

// For maintaining the subsets we can use the bitmasks to represent the remaining nodes in our subset. Since bits are faster to operate and there are
// only few nodes in graph, bitmasks is better to use.

// For example: –  

// 10100 represents node 2 and node 4 are left in set to be processed

// 010010 represents node 1 and 4 are left in subset.

// NOTE:- ignore the 0th bit since our graph is 1-based

#include <iostream>

using namespace std;

// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of
	// all possible j nodes

	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i)))
									+ dist[j][i]);
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1)
								+ dist[i][1]);

	printf("The cost of most efficient tour = %d", ans);

	return 0;
}

// This code is contributed by Serjeel Ranjan

