// Create an array arr[] of size n, where n is the number of nodes in the given BST.
// Perform the inorder traversal of the BST and copy the node values in the arr[] in sorted order.
// Now perform the preorder traversal of the tree.
// While traversing the root during the preorder traversal, one by one copy the values from the array arr[] to the nodes.

// C++ implementation to convert the given
// BST to Min Heap
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node {
	int data;
	Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct Node* getNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// function prototype for preorder traversal
// of the given tree
void preorderTraversal(Node*);

// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorderTraversal(Node* root, vector<int>& arr)
{
	if (root == NULL)
		return;

	// first recur on left subtree
	inorderTraversal(root->left, arr);

	// then copy the data of the node
	arr.push_back(root->data);

	// now recur for right subtree
	inorderTraversal(root->right, arr);
}

// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> arr, int* i)
{
	if (root == NULL)
		return;

	// first copy data at index 'i' of 'arr' to
	// the node
	root->data = arr[++*i];

	// then recur on left subtree
	BSTToMinHeap(root->left, arr, i);

	// now recur on right subtree
	BSTToMinHeap(root->right, arr, i);
}

// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node* root)
{
	// vector to store the data of all the
	// nodes of the BST
	vector<int> arr;
	int i = -1;

	// inorder traversal to populate 'arr'
	inorderTraversal(root, arr);

	// BST to MIN HEAP conversion
	BSTToMinHeap(root, arr, &i);
}

// function for the preorder traversal of the tree
void preorderTraversal(Node* root)
{
	if (!root)
		return;

	// first print the root's data
	cout << root->data << " ";

	// then recur on left subtree
	preorderTraversal(root->left);

	// now recur on right subtree
	preorderTraversal(root->right);
}

// Driver program to test above
int main()
{
	// BST formation
	struct Node* root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(6);
	root->left->left = getNode(1);
	root->left->right = getNode(3);
	root->right->left = getNode(5);
	root->right->right = getNode(7);

	convertToMinHeapUtil(root);
	cout << "Preorder Traversal:" << endl;
	preorderTraversal(root);

	return 0;
}

