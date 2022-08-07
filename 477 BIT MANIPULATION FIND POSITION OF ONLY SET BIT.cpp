// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        
        int bit=N;
        int pos=1;
        int ans;
        int more=0;
        if(N==0)
        return -1;
        int x=0;
        int set=bit&1;
        bit=bit>>1;
        while(bit)
        {
            // int set=bit&1;
            if(set)
            {
                ans=pos;
                more++;
                if(more>1)
                return -1;
                
            }
            set=bit&1;
            bit=bit>>1;
            
            pos++;
        }
        return pos;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
