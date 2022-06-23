// c++ program for stack implementatoion.

// Stack is a linear data structure that follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out)
// or FILO(First In Last Out). This strategy states that the element that is inserted last will come out first. You can take a pile of plates
// kept on top of each other as a real-life example. The plate which we put last is on the top and since we remove the plate that is at the top,
// we can say that the plate that was put last comes out first. Some of its main operations are: push(), pop(), top(), isEmpty(), size(), etc.
// In order to make manipulations in a stack, there are certain operations provided to us. When we want to insert an element into the stack the 
// operation is known as the push operation whereas when we want to remove an element from the stack the operation is known as the pop operation.
// If we try to pop from an empty stack then it is known as underflow and if we try to push an element in a stack that is already full, then it
// is known as overflow.
// Mainly the following four basic operations are performed in the stack:

// Push: Adds an item to the stack. If the stack is full, then it is said to be an Overflow condition.

// Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty,
// then it is said to be an Underflow condition.

// Peek or Top: Returns the top element of the stack.

// isEmpty: Returns true if the stack is empty, else false.

// Time Complexities of operations on the stack:
// push(), pop(), isEmpty() and peek() all take O(1) time. We do not run any loop in any of these operations.

// Applications of the stack:

// Balancing of symbols
// Infix to Postfix /Prefix conversion
// Redo-undo features at many places like editors, photoshop.
// Forward and backward features in web browsers
// Used in many algorithms like Tower of Hanoi, tree traversals, stock span problems, and histogram problems.
// Backtracking is one of the algorithm designing techniques. Some examples of backtracking are the Knight-Tour problem, N-Queen problem,
// find your way through a maze, and game-like chess or checkers in all these problems we dive into someway if that way is not efficient we come back
// to the previous state and go into some another path. To get back from a current state we need to store the previous state for that purpose we need
// a stack.
// In Graph Algorithms like Topological Sorting and Strongly Connected Components
// In Memory management, any modern computer uses a stack as the primary management for a running purpose. Each program that is running in a computer
// system has its own memory allocations
// String reversal is also another application of stack. Here one by one each character gets inserted into the stack. So the first character of
// the string is on the bottom of the stack and the last element of a string is on the top of the stack. After Performing the pop operations on the
// stack we get a string in reverse order.

// Implementation: 
// There are two ways to implement a stack: 

// Using array
// Using linked list


// STACK IMPLEMENTATION USING ARRAY:

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack

	Stack() { top = -1; }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

// Driver program to test above functions
int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << " Popped from stack\n";

	//print top element of stack after poping
	cout << "Top element is : " << s.peek() << endl;

	//print all elements in stack :
	cout<<"Elements present in stack : ";
	while(!s.isEmpty())
	{
		// print top element in stack
		cout<<s.peek()<<" ";
		// remove top element in stack
		s.pop();
	}

	return 0;
}




// STACK IMPLEMENTATION USING LINKED LIST:


// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a stack
class StackNode {
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data)
{
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(StackNode* root)
{
	return !root;
}

void push(StackNode** root, int data)
{
	StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	cout << data << " pushed to stack\n";
}

int pop(StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

// Driver code
int main()
{
	StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	cout << pop(&root) << " popped from stack\n";

	cout << "Top element is " << peek(root) << endl;
	
	cout<<"Elements present in stack : ";
	//print all elements in stack :
	while(!isEmpty(root))
	{
		// print top element in stack
		cout<<peek(root)<<" ";
		// remove top element in stack
		pop(&root);
	}

	return 0;
}
