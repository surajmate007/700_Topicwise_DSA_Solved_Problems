// A stack can be implemented using two queues. Let stack to be implemented be 's' and queues used to implement be 'q1' and 'q2'. Stack 's' can
// be implemented in two ways:
// Method 1 (By making push operation costly) 
// This method makes sure that newly entered element is always at the front of 'q1', so that pop operation just dequeues from 'q1'. 'q2' is used to
// put every new element at front of 'q1'.
 
// push(s, x) operation's step are described below: 
// Enqueue x to q2
// One by one dequeue everything from q1 and enqueue to q2.
// Swap the names of q1 and q2
// pop(s) operation's function are described below: 
// Dequeue an item from q1 and return it.

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}


//Function to pop an element from stack using two queues. 
int QueueStack :: pop(){
    if(!q1.empty()){
        int val = q1.front();
        q1.pop();
        return val;
    }
    return -1;
}



// Method 3 (Using only 1 queue):

// In this method we will be using only one queue and make the queue act as stack. The idea behind this approach is to make one queue and push the
// first element in it. After the first element, we push the next element and then push the first element again and finally pop the first element.
// So, according to the FIFO rule of queue, second element that was inserted will be at the front and then the first element as it was pushed again
// later and its first copy was popped out. So, this acts as a stack and we do this at every step i.e. from the initial element to the second last
// element and the last element will be the one which we are inserting and since we will be pushing the initial elements after pushing the last
// element, our last element becomes the first element.


#include <bits/stdc++.h>
using namespace std;

// Stack Class that acts as a queue
class Stack {

    queue<int> q;

public:
    void push(int data);
    void pop();
    int top();
    bool empty();
};

// Push operation
void Stack::push(int data)
{
    //  Get previous size of queue
    int s = q.size();

    // Push the current element
    q.push(data);

    // Pop all the previous elements and put them after
    // current element

    for (int i = 0; i < s; i++) {
        // Add the front element again
        q.push(q.front());

        // Delete front element
        q.pop();
    }
}

// Removes the top element
void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}

// Returns top of stack
int Stack::top() { return (q.empty()) ? -1 : q.front(); }

// Returns true if Stack is empty else false
bool Stack::empty() { return (q.empty()); }

 
