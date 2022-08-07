// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void solve(int N, int arr[], int i,int sum, int rsum,int &ans)
    {
        if(sum==rsum)
        {
            ans+=1;
            return ;
        }
        if(ans>0 || i==N || rsum>sum)
        return;
        
        rsum+=arr[i];
        i+=1;
        solve(N,arr,i,sum,rsum,ans);
        rsum-=arr[i-1];
        solve(N,arr,i,sum,rsum,ans);
        
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2!=0)
        return 0;
        
        sum=sum/2;
        
        int ans=0;
        
        solve(N,arr,0,sum,0,ans);
        if(ans==0)
        return 0;
        else
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
