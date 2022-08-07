// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node,vector<int> adj[],vector<bool> &vis,stack<int> &st){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it,adj,vis,st);
        }
        st.push(node);
    }
    
	void dfs1(int node,vector<int> adj2[],vector<bool> &vis){
        vis[node] = true;
        for(auto it : adj2[node]){
            if(!vis[it]) dfs1(it,adj2,vis);
        }
    }
    
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int v=V;
        int ans = 0;
        stack<int> st;
        
        // step 1 : random order dfs
        vector<bool> vis(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        // step 2 : reverse all edges
        vector<int> adj2[v];
        for(int i=0;i<v;i++){
            for(auto node : adj[i]){
                adj2[node].push_back(i);
            }
        }
        
        // fill(vis.begin(),vis.end(),false);
        for(int i=0;i<v;i++){
            vis[i]=false;
        }
        // step 3 : call dfs from stack's top
        while(st.size()){
            auto node = st.top(); st.pop();
            if(vis[node]) continue;
            ans++;
            dfs1(node,adj2,vis);
        }
        
        return ans;
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
