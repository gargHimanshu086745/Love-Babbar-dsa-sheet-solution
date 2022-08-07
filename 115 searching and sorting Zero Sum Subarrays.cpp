//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
         vector<int> pre(n+1,0);
        unordered_map<int,int> um;
        um[0]=1;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+arr[i];
            if(um.count(pre[i+1]))
                ans+=um[pre[i+1]];
            um[pre[i+1]]++;    
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends
