void dfs(int src, vector<int> &vis, vector<vector<int>> astronaut, int &counter)
{
    vis[src]=1;
    counter++;
    for(auto x:astronaut[src])
    {
        if(!vis[x])
        {
            dfs(x,vis,astronaut,counter);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {

    vector<int> solution;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            int counter=0;
            dfs(i,vis,astronaut,counter);
            solution.push_back(counter);
        }
    }
    
    int val = (n*(n-1))/2;
    for(int i=0;i<solution.size();i++)
    {
        int x = (solution[i]*(solution[i]-1)) / 2;
        val = val-x;
    }
    return val;
}
