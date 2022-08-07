// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here\
        
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            // cout<<a[i]<<endl;
            if(a[i]<0 && k>0)
            {
                a[i]=-a[i];
                k--;
            }
            else
            break;
        }
        
        sort(a,a+n);
        if(k%2)
        {
           a[0]=-a[0];
        //   cout<<a[0]<<endl; 
        }
        
        
        // cout<<a[0]<<endl;
        long long sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends
