// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int dfs(pair<int,int>adj[],int node,int& dim){
       if(!adj[node].first){
           return node;
       }
       
       dim=min(dim,adj[node].second);
       return dfs(adj,adj[node].first,dim);
       
   }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        pair<int,int>adj[n+1];
       
       int indegree[n+1];
       for(int i=0;i<=n;i++){
           indegree[i]=0;
       }
       
       for(int i=0;i<p;i++){
           adj[a[i]]={b[i],d[i]};
           indegree[b[i]]++;
       }
       
       vector<vector<int>>sol;
       
       for(int i=1;i<=n;i++){
           if(indegree[i]==0 && adj[i].first){
               int dim=adj[i].second;
               int src=adj[i].first;
               
               int end=dfs(adj,src,dim);
               
               if(i!=end){
                   sol.push_back({i,end,dim});
               }
               
           }
       }
       
       return sol;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends
