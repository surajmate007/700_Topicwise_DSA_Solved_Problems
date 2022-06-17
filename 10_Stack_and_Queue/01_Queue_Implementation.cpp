// Similar to Stack, Queue is a linear data structure that follows a particular order in which the operations are performed for storing data. The order
// is First In First Out (FIFO).  One can imagine a queue as a line of people waiting to receive something in sequential order which starts from the
// beginning of the line. It is an ordered list in which insertions are done at one end which is known as the rear and deletions are done from the other
// end known as the front. A good example of a queue is any queue of consumers for a resource where the consumer that came first is served first. 
// The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least
// recently added.
// Basic Operations on Queue: 

// void enqueue(int data): Inserts an element at the end of the queue i.e. at the rear end.
// int dequeue(): This operation removes and returns an element that is at the front end of the queue.
// Auxiliary Operations on Queue:

// int front(): This operation returns the element at the front end without removing it.
// int rear(): This operation returns the element at the rear end without removing it.
// int isEmpty(): This operation indicates whether the queue is empty or not.
// int size(): This operation returns the size of the queue i.e. the total number of elements it contains.  

// Types of Queues: 

// Simple Queue: Simple queue also known as a linear queue is the most basic version of a queue. Here, insertion of an element i.e. the Enqueue
// operation takes place at the rear end and removal of an element i.e. the Dequeue operation takes place at the front end.
// Circular Queue:  In a circular queue, the element of the queue act as a circular ring. The working of a circular queue is similar to the linear queue
// except for the fact that the last element is connected to the first element. Its advantage is that the memory is utilized in a better way.This is because
// if there is an empty space i.e. if no element is present at a certain position in the queue, then an element can be easily added at that position.
// Priority Queue: This queue is a special type of queue. Its specialty is that it arranges the elements in a queue based on some priority.
// The priority can be something where the element with the highest value has the priority so it creates a queue with decreasing order of values.
// The priority can also be such that the element with the lowest value gets the highest priority so in turn it creates a queue with increasing order
// of values.
// Dequeue: Dequeue is also known as Double Ended Queue. As the name suggests double ended, it means that an element can be inserted or removed from
// both the ends of the queue unlike the other queues in which it can be done only from one end. Because of this property it may not obey the First In
// First Out property. 

// Applications of Queue: 
// Queue is used when things don’t have to be processed immediately, but have to be processed in First In First Out order like Breadth First Search.
// This property of Queue makes it also useful in following kind of scenarios.
// 1) When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling. 
// 2) When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO
// Buffers, pipes, file IO, etc. 


// 3) Queue can be used as an essential component in various other data structures.
// See this for more detailed applications of Queue and Stack.
// Array implementation Of Queue 
// For implementing queue, we need to keep track of two indices, front and rear. We enqueue an item at the rear and dequeue an item from the front.
// If we simply increment front and rear indices, then there may be problems, the front may reach the end of the array. The solution to this problem
// is to increase front and rear in circular manner.

// Steps for ENQUEUE

// Check the queue is full or not
// If full, print overflow and exit
// If queue is not full, increment tail and add the element
// Steps for DEQUEUE

// Check queue is empty or not
// if empty, print underflow and exit
// if not empty, print element at the head and increment head



// CPP program for array
// implementation of queue
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a queue
class Queue {
public:
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
Queue* createQueue(unsigned capacity)
{
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// This is important, see the enqueue
	queue->rear = capacity - 1;
	queue->array = new int[queue->capacity];
	return queue;
}

// Queue is full when size
// becomes equal to the capacity
int isFull(Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue* queue)
{
	return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)
				% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)
				% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue
int front(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

// Driver code
int main()
{
	Queue* queue = createQueue(1000);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	cout << dequeue(queue)
		<< " dequeued from queue\n";

	cout << "Front item is "
		<< front(queue) << endl;
	cout << "Rear item is "
		<< rear(queue) << endl;

	return 0;
}

// This code is contributed by rathbhupendra

