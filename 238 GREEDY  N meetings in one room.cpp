// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool comp(pair<int,int> p1, pair<int,int> p2)
    {
        return p2.second>p1.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int> > v(n);
        for(int i=0;i<n;i++)
        v[i]={start[i],end[i]};
        
        sort(v.begin(),v.end(),comp);
        
        int j=1;
        int i=0;
        int job=1;
        
        while(j<n)
        {
            if(v[i].second<v[j].first)
            {
                i=j;
                j++;
                job++;
                
            }
            else
            j++;
        }
        
        return job;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
