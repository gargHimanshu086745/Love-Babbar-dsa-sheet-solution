//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        
        int i=0;
        int ans=0;
        while(i<s.length())
        {
            if(s[i]=='(')
            {
                st.push(i);
                // ans++;
            }
            else
            {
                if(!st.empty() && s[st.top()]=='(')
                {
                    st.pop();
                    // ans++;
                }
                else
                {
                    st.push(i);
                }
            }
            i++;
        }
        int curr=s.length();
        bool first=true;
        int top;
        if(st.empty())
        return curr;
        else
        while(!st.empty())
        {
            top=st.top();
            if(first)
            {
                // st.pop();
                curr=curr-top-1;
                ans=max(ans,curr);
                first =false;
                
            }
            else
            {
                st.pop();
                if(st.size()==0)
                {
                    top=top;
                    ans=max(ans,top);
                }
                else
                {
                    int stop=st.top();
                    curr=top-stop-1;
                    ans=max(ans,curr);
                }
                
            }
        }
        // int size = st.size();
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends
