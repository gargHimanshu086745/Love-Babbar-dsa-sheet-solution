// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8] = {2,2,-2,-2,1,-1,1,-1};
    int dy[8] = {1,-1,1,-1,2,2,-2,-2};
    vector<vector<int>> dist;
    
    bool isSafe(int x,int y,int N){
        return (x >= 0 && y >= 0 && x <= N && y <= N);
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    dist = vector<vector<int>>(N+1,vector<int>(N+1,0));
	    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) return 0;
        queue<pair<int,int>> q;
        q.push(make_pair(KnightPos[0],KnightPos[1]));
        while(!q.empty()){
            pair<int,int> xx = q.front();
            q.pop();
            for(int i=0;i<8;i++){
                if(isSafe(xx.first + dx[i],xx.second + dy[i],N) && (dist[xx.first + dx[i]][xx.second + dy[i]]) == 0){
                    if(xx.first+dx[i]==TargetPos[0] && xx.second + dy[i] == TargetPos[1])
                    {
                        if(dist[xx.first + dx[i]][xx.second + dy[i]]==0)
                        dist[xx.first + dx[i]][xx.second + dy[i]] = dist[xx.first][xx.second] + 1;
                        else if(dist[xx.first + dx[i]][xx.second + dy[i]]>dist[xx.first][xx.second] + 1)
                        dist[xx.first + dx[i]][xx.second + dy[i]] = dist[xx.first][xx.second] + 1;
                    }
                    else
                    {
                        dist[xx.first + dx[i]][xx.second + dy[i]] = dist[xx.first][xx.second] + 1;
                        q.push(make_pair(xx.first + dx[i],xx.second + dy[i]));
                    }
                    
                }
            }   
        }
        if(dist[TargetPos[0]][TargetPos[1]] == 0) return -1;
        return dist[TargetPos[0]][TargetPos[1]];
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
