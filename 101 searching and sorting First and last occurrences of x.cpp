//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    int ind=-1;
    int low=0;
    int end=n-1;
    int mid;
    int first,last;
    while(low<=end)
    {
        mid=(low+end)/2;
        
        if(arr[mid]==x)
        {
            ind=mid;
            break;
        }
        else if(arr[mid]<x)
        {
            low =mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    
    first=ind,last=ind;
    for(int i=ind-1;i>=0;i--)
    {
        if(arr[i]==x)
        {
            first--;
        }
    }
    for(int i=ind+1;i<n;i++)
    {
        if(arr[i]==x)
        {
            last++;
        }
    }
    
    vector<int> v;
    v.push_back(first);
    v.push_back(last);
    return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
