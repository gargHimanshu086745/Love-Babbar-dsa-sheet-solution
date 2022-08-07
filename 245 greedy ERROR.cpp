// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	set<pair<int,int>> s;
        set<pair<int,int>>:: iterator it1,it2;
    	for(int i=0;i<n;i++)
    	{
    	    pair<int,int> p= make_pair(dep[i],arr[i]);
    	    s.insert(p);
    	}
    	
    	
    // 	it1=s.begin();
    	int platform=0;
    	
    // 	s.erase(it);
    // 	it2=s.begin();
    	while(!s.empty())
    	{
    	    it1=s.begin();
    	    platform++;
    	    s.erase(it1);
    	    it2=s.begin();
    	    for(; it2!=s.end();it2++)
    	    if(it2->second>=it1->first)
    	    {
    	        it1=it2;
    	        s.erase(it2);
    	    }
    	}
    // 	cout<<it2->first<<" "<<it2->second<<" "<<endl;
        
        
        
        
        // for(x:s)
        // {
        //     if(x.first==1120)
        //     s.erase(x);
        //     cout<<x.first<<" "<<x.second<<" "<<endl;
        // }
        return platform;
    
    // return 0;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
