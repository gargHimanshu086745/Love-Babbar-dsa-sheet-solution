//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        int i,c;
        unordered_map<int,vector<int>> mp;
       priority_queue<int> x;
       for(i=0;i<n;i++)
       {   
           c=0;
           int n1=arr[i];
           while(n1!=0)
           {
               n1= n1 & n1-1;
               c++;
               if(n1==0)
               {
                   mp[c].push_back(arr[i]);
                   break;
               }
              
           }
           
       }
      
        for(auto j : mp)
        {
            x.push(j.first);
        }
       int m=0,n2=0;
        while(!x.empty())
        {   
           n2=0;
            int p=(mp[x.top()]).size();
            while(p>0)
            {
               arr[m]=mp[x.top()][n2] ;
               m++;
               n2++;
               p--;
            }
            x.pop();
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
