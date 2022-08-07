//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // stack<int> s;
    bool solve(int N,vector<int> &A,vector<int> &B)
    {
        queue<int> input;
        for(int i=0;i<N;i++)
        {
            input.push(A[i]);
        }
        
        queue<int> output;
        for(int i=0;i<N;i++)
        {
            output.push(B[i]);
        }
        
        stack<int> tempStack;
        while(!input.empty())
        {
            int ele=input.front();
            input.pop();
            if(ele==output.front())
            {
                output.pop();
                while(!tempStack.empty())
                {
                    if(tempStack.top()==output.front())
                    {
                        output.pop();
                        tempStack.pop();
                    }
                    else 
                    break;
                }
            }
            else
            tempStack.push(ele);
        }
        return (input.empty()&& tempStack.empty());
    }
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        int ans=solve(N,A,B);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
