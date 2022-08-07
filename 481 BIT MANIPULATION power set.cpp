// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    int n=pow(2,s.length());
		    string c="";
		    for(int i=1; i<n;i++)
		    {
		        int x=i;
		        int j=0;
		        string c="";
		        while(x)
		        {
		            if(x&1)
		            {
		                c= c+s[j];
		            }
		            x=x>>1;
		            j++;
		        }
		        ans.push_back(c);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
