int n;
//declaring min heap node.
struct MinHeapNode
{
    //the element to be stored.
	int element; 
	//index of the array from which the element is taken.
	int i;
	//index of the next element to be picked from array.
	int j; 
};


void swap(MinHeapNode *x, MinHeapNode *y);


class MinHeap
{
	MinHeapNode *harr;
	int heap_size; 
	
    public:
	// Constructor: creates a min heap of given size.
	MinHeap(MinHeapNode a[], int size);

	//to heapify a subtree with root at given index.
	void MinHeapify(int );

	//to get index of left child of node at index i.
	int left(int i) { return (2*i + 1); }

	//to get index of right child of node at index i.
	int right(int i) { return (2*i + 2); }

	//to get the root.
	MinHeapNode getMin() { return harr[0]; }

	//to replace root with new node x and heapify() new root.
	void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }
};


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        n = k;
    	vector<int> output(n*k);
    	
    	//creating a min heap with k heap nodes. Every heap node
    	//has first element of an array.
    	MinHeapNode *harr = new MinHeapNode[k];
    	for (int i = 0; i < k; i++)
    	{
    	    //storing the first element.
    		harr[i].element = arr[i][0]; 
    		// index of array
    		harr[i].i = i;
    		// Index of next element to be stored from array
    		harr[i].j = 1; 
    	}
    	MinHeap hp(harr, k); 
    
    	//Now one by one we get the minimum element from min
    	//heap and replace it with next element of its array.
    	for (int count = 0; count < n*k; count++)
    	{
    		//getting the minimum element and storing it in output.
    		MinHeapNode root = hp.getMin();
    		output[count] = root.element;
    
    		//finding the next element that will replace current root of heap.
    		//The next element belongs to same array as the current root.
    		if (root.j < n)
    		{
    			root.element = arr[root.i][root.j];
    			root.j += 1;
    		}
    		//if root was the last element of its array, we store INT_MAX.
    		else root.element = INT_MAX; 
    
    		//replacing root with next element of array.
    		hp.replaceMin(root);
    	}
    
    	return output;
    }
};


// Constructor: Builds a heap from a given array a[] of given size.
MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	harr = a; 
	int i = (heap_size - 1)/2;
	while (i >= 0)
	{
		MinHeapify(i);
		i--;
	}
}

//a recursive method to heapify a subtree with root at given index.
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].element < harr[i].element)
		smallest = l;
	if (r < heap_size && harr[r].element < harr[smallest].element)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

//Function to swap two nodes.
void swap(MinHeapNode *x, MinHeapNode *y)
{
	MinHeapNode temp = *x; *x = *y; *y = temp;
}
