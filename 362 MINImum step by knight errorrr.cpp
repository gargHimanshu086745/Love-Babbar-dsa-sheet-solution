// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isSafe(int N, int x, int y)
    {
        if((x>=1 && x<=N ) && (y>=1 && y<=N))
        {
            return true;
        }
        else
        return false;
    }
    void solve(int N, int X[], int Y[],set<int> &ans,int path, vector<int>&KnightPos,vector<int>&TargetPos,unordered_map<pair<int,int>,int, hash_pair> &visited)
    {
        if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1])
        {
            ans.insert(path);
            return ;
        }
        
        for(int i=0;i<8;i++)
        {
             KnightPos[0] = KnightPos[0]+X[i];
             KnightPos[1] = KnightPos[1]+Y[i];
             
            
            if(isSafe(N, KnightPos[0],KnightPos[1]))
            {
                if(!visited[{KnightPos[0],KnightPos[1]}])
                {
                    visited[{KnightPos[0],KnightPos[1]}=1;
                    solve(N,X,Y,ans,path+1,KnightPos,TargetPos);
                    visited[{KnightPos[0],KnightPos[1]}=0;
                }
                
            }
            KnightPos[0] = KnightPos[0]-X[i];
            KnightPos[1] = KnightPos[1]-Y[i];
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    int X[8] = { -1, 1, 2, -2, -1, 1, 2, -2 };
        int Y[8] = { 2, 2,  1,  1, -2, -2,-1,-1 };
	    
	    set<int> ans;
	    int  path=0;
	    int x = KnightPos[0];
	    int y= KnightPos[1];
	   unordered_map<pair<int,int>,bool, hash_pair> visited;
	   pair<int, int> p(KnightPos[0],KnightPos[1]);
	   visited[p]=true;
	    solve(N,X,Y,ans,path,KnightPos,TargetPos,visited);
	   
	   
	   
	    int min=ans[0];
	    return min;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
