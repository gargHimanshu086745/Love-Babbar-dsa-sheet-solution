//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

bool binary_search(int arr[],int start ,int end , int y)
{
    int l=start,h=end-1;
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        
        if(arr[mid]==y)
        return true;
        else if(arr[mid]>y)
        h=mid-1;
        else
        l=mid+1;
    }
    return false;
}
bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    
    for(int i=0;i<size;i++)
    {
        int sum=arr[i]+n;
        bool check=binary_search(arr, i+1,size,sum);
        if(check)
        return true;
    }
    return false;
}
