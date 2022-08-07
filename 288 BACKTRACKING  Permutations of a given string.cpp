// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string s, string temp, vector<string> &ans, int check[])
	    {
	        if(temp.length()==s.length())
	        {
	            ans.push_back(temp);
	            return;
	        }
	        for(int i=0;i<s.length();i++)
	        {
	            if(!check[i])
	            {
	                check[i]=1;
	                temp+= s[i];
	                solve(s,temp,ans,check);
	               // temp.substr(0, temp.length()-2);
	               
	                check[i]=0;
	                temp.pop_back();
	            }
	        }
	        
	        
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    string temp="";
		    int check[S.length()];
		    for(int i=0;i<S.length();i++)
		    check[i]=0;
		    solve(S,temp,ans,check);
		    
		    // removing repeating  string due to repeating character in string 
		    
		    sort(ans.begin(),ans.end());
            ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
