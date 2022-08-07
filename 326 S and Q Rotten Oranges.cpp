//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
        // int tm=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                   q.push({i,j});
                }
                // solve(grid,visited,n,m,i,j);
            }
        }
        int count=0;
        q.push({-1,-1});
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            if(i==-1 && j==-1 && q.size()==1)
            {
                q.pop();
                break;
            }
            else if(i==-1 && j==-1 && q.size()>1)
            {
                count++;
                q.pop();
                q.push({-1,-1});
            }
            else
            {
                if((i-1)>=0 and grid[i-1][j]==1)
                {
                    grid[i-1][j] = 2;
                    q.push({i-1,j});
                }
                if((i+1)<n and grid[i+1][j]==1)
                {
                    grid[i+1][j] = 2;
                    q.push({i+1,j});
                }
                if((j+1)<m and grid[i][j+1]==1)
                {
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                }
                if((j-1)>=0 and grid[i][j-1]==1)
                {
                    grid[i][j-1] = 2;
                    q.push({i,j-1});
                }
                q.pop();
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                   return -1;
                }
                // solve(grid,visited,n,m,i,j);
            }
        }
        return count ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
