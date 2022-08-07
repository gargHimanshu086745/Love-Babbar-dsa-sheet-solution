//--------------------------- self solved------------------------------------------------
class Solution
{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        mergeSort(arr, 0, N-1);
        // for(int i=0;i<N;i++)
        // {
        //     cout<<" "<<arr[i];
        // }
        int count=1;
        int temp=1;
        for(int i=1;i<N;i++)
        {
            if(arr[i]==arr[i-1]+1)
            {
               temp++;
            }
            else if(arr[i]==arr[i-1])
            {
                continue;
            }
            else 
            {
                if(temp>count)
                {
                    count=temp;
                    temp=1;    
                }
                else
                {
                    temp=1;
                }
                
            }
        }
        if(temp>count)
        {
            count=temp;
            temp=1;    
        }
        return count;
    }
    void mergeSort(int array[], int const begin, int const end)
    {
        if (begin >= end)
            return; // Returns recursively
      
        auto mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
    
    void merge(int array[], int const left, int const mid, int const right)
    {
        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;
  
        // Create temp arrays
            auto *leftArray = new int[subArrayOne],
             *rightArray = new int[subArrayTwo];
      
        // Copy data to temp arrays leftArray[] and rightArray[]
        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];
      
        auto indexOfSubArrayOne = 0, // Initial index of first sub-array
            indexOfSubArrayTwo = 0; // Initial index of second sub-array
        int indexOfMergedArray = left; // Initial index of merged array
      
        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        // Copy the remaining elements of
        // left[], if there are any
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        // Copy the remaining elements of
        // right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }
};

//--------------------------------gfg solution-------------------------------
class Solution{
  public:
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //using a Set to store elements.
        unordered_set<int> S;
        int ans = 0;
 
        //inserting all the array elements in Set.
        for (int i = 0; i < n; i++)
           S.insert(arr[i]);
 
        //checking each possible sequence from the start.
        for (int i = 0; i < n; i++)
        {
           //if current element is starting element of a sequence then only 
           //we try to find out the length of sequence.
           if (S.find(arr[i] - 1) == S.end())
           {
               
                int j = arr[i];
                //then we keep checking whether the next consecutive elements
                //are present in Set and we keep incrementing the counter.
                while (S.find(j) != S.end())
                j++;
 
            //storing the maximum count.
            ans = max(ans, j - arr[i]);
            }
        }
        //returning the length of longest subsequence
        return ans;
    }
}; 
