// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void heapify(int arr[],int n, int i)
    {
        int largest =i;
        int l=2*i +1;
        int r=2*i +2;
        
        if(l<n && arr[l]>arr[largest])
        largest=l;
        if(r<n && arr[r]>arr[largest])
        largest=r;
        
        if(largest!=i)
        {
            swap(arr[i],arr[largest]);
            
            heapify(arr,n,largest);
        }
    }
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    
	    int h=n/2 -1 ;
	    for(int i=h;i>=0;i--)
	    {
	        heapify(arr,n,i);
	    }
	    vector<int> ans;
	    for(int i=n-1;i>n-1-k;i--)
	    {
	        swap(arr[0],arr[i]);
	        heapify(arr,i,0);
	        ans.push_back(arr[i]);
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
