// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int setBits(long long int N) {
        // Write Your Code here
        
        vector<int> bin;
        // int i=0;
        while(N)
        {
            bin.push_back(N%2);
            N=N/2;
        }
        
        int set=0;
        for(int i=0;i<bin.size();i++)
        {
            if(bin[i]==1)
            set++;
        }
        return set;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends
