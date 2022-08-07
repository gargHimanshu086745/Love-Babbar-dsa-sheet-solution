//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n= grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>> temp=grid;
	    
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            q.push({i,j});
	        }
	    }
	    int count=1;
	    q.push({-1,-1});
	    {
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
	                if((i-1)>=0 and grid[i-1][j]==0)
                    {
                        grid[i-1][j] = count;
                        q.push({i-1,j});
                    }
                    if((i+1)<n and grid[i+1][j]==0)
                    {
                        grid[i+1][j] = count;
                        q.push({i+1,j});
                    }
                    if((j+1)<m and grid[i][j+1]==0)
                    {
                        grid[i][j+1] = count;
                        q.push({i,j+1});
                    }
                    if((j-1)>=0 and grid[i][j-1]==0)
                    {
                        grid[i][j-1] = count;
                        q.push({i,j-1});
                    }
                    q.pop();
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(temp[i][j]==1)
	            grid[i][j]=0;
	            else
	            continue;
	        }
	    }
	    return grid;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
