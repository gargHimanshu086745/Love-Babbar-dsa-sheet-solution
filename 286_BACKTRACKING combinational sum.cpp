// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void solve(vector<vector<int>> &ans,vector<int> temp,vector<int> &A,int B,int sum,int i )
    {
        if(i==A.size())
        return;
        
        if(sum==B)
        {
        
            ans.push_back(temp);
            return;
        }
        if(sum>=B)
        return;
        
        sum=sum+A[i];
        temp.push_back(A[i]);
        solve(ans,temp,A,B,sum,i);
        
        sum=sum-A[i];
        i++;
        temp.pop_back();
        solve(ans,temp,A,B,sum,i);
        
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        // set<vector<int>>ans;
        vector<vector<int>>ans;
        // set<vector<int>>vec;
        vector<int> temp;
        sort(A.begin(),A.end());
        A.erase( unique( A.begin(), A.end() ), A.end() );
       
      
        solve(ans,temp,A,B,0,0);
        
    //   vector<vector<int>> final(ans.begin(), ans.end());
        
        // sort(ans.begin(),ans.end());
        // return final;
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
