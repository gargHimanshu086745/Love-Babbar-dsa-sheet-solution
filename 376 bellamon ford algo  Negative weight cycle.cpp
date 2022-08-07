// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    int src=0;
	     
	    int inf=100000000;
	    vector<int> dist(n,inf);
	    dist[src]=0;
	    
	    for(int i=1; i<=n-1;i++)
	    {
	        for(auto it: edges)
	        {
	            auto x=it.begin();
	            int first=*x;
	            x++;
	            int second= *x;
	            x++;
	            int third = *x;
	            if(dist[first] + third < dist[second])
	            {
	                dist[second]  = dist[first] + third;
	            }
	        }
	    }
	    
	    
	    int fl=0;
	    
	    for(auto it:edges)
	    {
	        auto x=it.begin();
	        int first=*x;
	        x++;
	        int second= *x;
	        x++;
	        int third = *x;
	        if(dist[first] + third < dist[second])
            {
	            fl=1;
	        }
	    }
	    if(fl)
	    return 1;
	    else
	    return 0;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
