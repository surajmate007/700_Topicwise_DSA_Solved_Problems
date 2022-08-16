// The problem might look complex at first look. But our final goal is to only build the max heap. The idea is very simple – we simply build Max Heap
// without caring about the input. We start from the bottom-most and rightmost internal mode of min Heap and heapify all internal modes in the bottom-up
// way to build the Max heap.
  
// Below is its implementation

void MaxHeapify(int arr[], int i, int n){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
  
    if (l < n && arr[l] > arr[largest])
        largest = l;
  
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    if (largest != i){
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, n);
    }
}
 
// This function basically builds max heap
void convertMaxHeap(int arr[], int n){
    // Start from bottommost and rightmost
    // internal mode and heapify all internal
    // modes in bottom up way
    for (int i = (n/2)-1; i >= 0; --i)
        MaxHeapify(arr, i, n);
}
