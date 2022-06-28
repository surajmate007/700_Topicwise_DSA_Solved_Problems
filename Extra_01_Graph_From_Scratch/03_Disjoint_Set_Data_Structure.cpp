// Consider a situation with a number of persons and following tasks to be performed on them.

// Add a new friendship relation, i.e., a person x becomes friend of another person y.
// Find whether individual x is a friend of individual y (direct or indirect friend)

// We are given 10 individuals say,
// a, b, c, d, e, f, g, h, i, j

// Following are relationships to be added.
// a <-> b  
// b <-> d
// c <-> f
// c <-> i
// j <-> e
// g <-> j

// And given queries like whether a is a friend of d
// or not.

// We basically need to create following 4 groups
// and maintain a quickly accessible connection
// among group items:
// G1 = {a, b, d}
// G2 = {c, f, i}
// G3 = {e, g, j}
// G4 = {h}

// Problem : To find whether x and y belong to same group or not, i.e., to find if x and y are direct/indirect friends.
// Solution : Partitioning the individuals into different sets according to the groups in which they fall. This method is known as disjoint set data
// structure which maintains collection of disjoint sets and each set is represented by its representative which is one of its members.

// Improvements (Union by Rank and Path Compression) 
// The efficiency depends heavily on the height of the tree. We need to minimize the height of tree in order to improve the efficiency. We can use Path
// Compression and Union by rank methods to do so.

// Path Compression (Modifications to find()) : It speeds up the data structure by compressing the height of the trees. It can be achieved by inserting
// a small caching mechanism into the Find operation. Take a look at the code for more details:

// Union by Rank: First of all, we need a new array of integers called rank[]. Size of this array is same as the parent array. If i is a representative
// of a set, rank[i] is the height of the tree representing the set. 
// Now recall that, in the Union operation, it doesn’t matter which of the two trees is moved under the other (see last two image examples above).
// Now what we want to do is minimize the height of the resulting tree. If we are uniting two trees (or sets), let’s call them left and right, then it
// all depends on the rank of left and the rank of right. 

// If the rank of left is less than the rank of right, then it’s best to move left under right, because that won’t change the rank of right
// (while moving right under left would increase the height). In the same way, if the rank of right is less than the rank of left, then we should move
// right under left.
// If the ranks are equal, it doesn’t matter which tree goes under the other, but the rank of the result will always be one greater than the rank of the
// trees.



// C++ implementation of disjoint set
#include <iostream>
using namespace std;
class DisjSet {
	int *rank, *parent, n;

public:
	// Constructor to create and
	// initialize sets of n items
	DisjSet(int n){
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	// Creates n single item sets
	void makeSet(){
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	// Finds set of given item x
	int find(int x){
		// Finds the representative of the set
		// that x is an element of
		if (parent[x] != x) {

			// if x is not the parent of itself
			// Then x is not the representative of
			// his set,
			parent[x] = find(parent[x]);

			// so we recursively call Find on its parent
			// and move i's node directly under the
			// representative of this set
		}

		return parent[x];
	}

	// Do union of two sets represented
	// by x and y.
	void Union(int x, int y){
		// Find current sets of x and y
		int xset = find(x);
		int yset = find(y);

		// If they are already in same set
		if (xset == yset)
			return;

		// Put smaller ranked item under
		// bigger ranked item if ranks are
		// different
		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}

		// If ranks are same, then increment
		// rank.
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};

int main(){
	DisjSet obj(5);
	obj.Union(0, 2);
	obj.Union(4, 2);
	obj.Union(3, 1);
	if (obj.find(4) == obj.find(0))
		cout << "Yes\n";
	else
		cout << "No\n";
	if (obj.find(1) == obj.find(0))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}

