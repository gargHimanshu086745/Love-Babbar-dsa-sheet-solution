//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        int ma = 0;
        
        
        int r = n;
        
        if(r==0)
        return 0;
        
        int c =m;
        
        
        int arr[c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0)
                arr[j]=M[i][j];
                else
                {
                    if(M[i][j]==1)
                    arr[j]++;
                    else
                    arr[j]=0;
                }
            }
            
            stack<int> s;
            int k=0;
            while(k<c)
            {
                if(s.empty() || arr[s.top()]<=arr[k])
                {
                    s.push(k++);
                }
                else
                {
                    int tp = s.top();
                    s.pop();
                    int ans = arr[tp]*(s.empty()? k: k - s.top()-1);
                    ma = max(ans,ma);
                }
            }
            while(!s.empty())
            {
                int  tp=s.top();
                s.pop();
                int ans = arr[tp]*(s.empty()? k : k- s.top()-1);
                ma = max(ans,ma);
            }
            
        }
        
        
        
        return ma;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
