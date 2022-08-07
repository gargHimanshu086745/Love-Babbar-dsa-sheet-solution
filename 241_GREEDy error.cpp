// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int dfs(unordered_map<int,list<pair<int,int>>> &adj,int src , int &ans)
    {
        
        stack<int> s;
        s.push(src);
        
        int top;
        
        
        while(!s.empty())
        {
            top=s.top();
            s.pop();
            
            auto neighbour= adj[top];
            if(neighbour.first!=0)
            {
                
                s.push(neighbour.first);
                ans=min(ans,neighbour.second);
            }
        }
        
        return top;
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        unordered_map<int,list<pair<int,int>>> adj;
        
        
        int indegree[n+1];
        for(int i=0;i<=n;i++){
            indegree[i]=0;
        }
        
        for(int i=0;i<p;i++)
        {
            pair<int,int> p = make_pair(b[i],d[i]);
            
            pair<int,int> p2 = make_pair(0,0);
            
            adj[a[i]].push_back(p);
            ad[b[i]].push_back(p2)
            indegree[b[i]]++;
        }
        
        vector<vector<int>> sol;
        
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0 && adj[i].first)
            {
                int ans = adj[i].second;
                int src=adj[i].first;
                
                int end = dfs(adj,src,ans);
            }
            
            if(i!=end)
            {
                sol.push_back(i,end,ans);
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
