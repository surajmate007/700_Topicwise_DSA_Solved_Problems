// Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position
// is connected back to the first position to make a circle. It is also called ‘Ring Buffer’. 
  
// Front: Get the front item from queue.
// Rear: Get the last item from queue.
// enQueue(value) This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at Rear position. 
// Check whether queue is Full – Check ((rear == SIZE-1 && front == 0) || (rear == front-1)).
// If it is full then display Queue is full. If queue is not full then, check if (rear == SIZE – 1 && front != 0) if it is true then set rear=0 and insert element.
// deQueue() This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from front position. 
// Check whether queue is Empty means check (front==-1).
// If it is empty then display Queue is empty. If queue is not empty then step 3
// Check if (front==rear) if it is true then set front=rear= -1 else check if (front==size-1), if it is true then set front=0 and return the element.

// Time Complexity: Time complexity of enQueue(), deQueue() operation is O(1) as there is no loop in any of the operation.
// Applications: 
 
// Memory Management: The unused memory locations in the case of ordinary queues can be utilized in circular queues.
// Traffic system: In computer controlled traffic system, circular queues are used to switch on the traffic lights one by one repeatedly as per the time set.
// CPU Scheduling: Operating systems often maintain a queue of processes that are ready to execute or that are waiting for a particular event to occur.



// C or C++ program for insertion and
// deletion in Circular Queue
#include<bits/stdc++.h>
using namespace std;

class Queue
{
	// Initialize front and rear
	int rear, front;

	// Circular Queue
	int size;
	int *arr;
public:
	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}

	void enQueue(int value);
	int deQueue();
	void displayQueue();
};


/* Function to create Circular queue */
void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||
			(rear == (front-1)%(size-1)))
	{
		printf("\nQueue is Full");
		return;
	}

	else if (front == -1) /* Insert First Element */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}

/* Driver of the program */
int main()
{
	Queue q(5);

	// Inserting elements in Circular Queue
	q.enQueue(14);
	q.enQueue(22);
	q.enQueue(13);
	q.enQueue(-6);

	// Display elements present in Circular Queue
	q.displayQueue();

	// Deleting elements from Circular Queue
	printf("\nDeleted value = %d", q.deQueue());
	printf("\nDeleted value = %d", q.deQueue());

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);
	return 0;
}

