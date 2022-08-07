// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isPossible(vector<vector<int>> matrix, int r, int c, int n, int mid){
        int cnt = 0;
        
        for(int i=0;i<r;i++){
            int j = c - 1;
            if(mid >= matrix[i][j]){
                cnt += j + 1;
            } else {
                while(mid < matrix[i][j]) j--;
                cnt += j + 1;
            }
        }
        
        return cnt >= ((n + 1) / 2);
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here   
        int s = INT_MAX, e = INT_MIN;
        
        int n = r * c;
        int ans = 0;
        
        for(int i=0;i<r;i++){
            s = min(s, matrix[i][0]);
            e = max(e, matrix[i][c-1]);
        }
        
        
        while(s <= e){
            int mid = s + (( e - s ) / 2);
            if(isPossible(matrix, r, c, n, mid)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends
