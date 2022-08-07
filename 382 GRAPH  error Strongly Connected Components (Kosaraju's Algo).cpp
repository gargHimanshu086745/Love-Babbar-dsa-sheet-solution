// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void bridge(int u,bool visited[], int disc[], int low[],int parent[],vector<int> adj[] ,int &scc)
	{
	    static int time=0;
	    visited[u]=true;
	    disc[u] = low[u] = ++time;
	    
	    for(auto i =adj[u].begin(); i!=adj[u].end(); ++i)
	    {
	        int v=*i;
	        if(!visited[v])
	        {
	            parent[v] = u;
	            bridge(v,visited,disc,low,parent,adj,scc);
	            
	            low[u] = min(low[u], low[v]);
	            
	            if (low[v] > disc[u])
                    scc++;
	            
	        }
	        else if(v!=parent[u])
	        {
	            low[u] = min(low[u], disc[v]);
	        }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        
        int *disc= new int[V];
        bool *visited = new bool[V];
        int *low = new int[V];
        int *parent = new int[V];
        
        for(int i=0;i<V;i++)
        {
            parent[i]=NULL;
            visited[i]=false;
        }
        
        int scc=1;
        
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            bridge(i,visited,disc,low,parent,adj,scc);
        }
        return scc;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
