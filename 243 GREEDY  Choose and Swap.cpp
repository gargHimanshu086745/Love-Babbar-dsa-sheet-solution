// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        set<char> s;
        
        for(int i=0;i<a.length();i++)
        {
            s.insert(a[i]);
        }
        
        for(int i=0;i<a.length();i++)
        {
            s.erase(a[i]);
            if(s.empty())
            break;
            
            char ch=*s.begin();
            
            if(ch<a[i])
            {
                int ch2= a[i];
                for(int j=0;j<a.length();j++)
                {
                    if(a[j]==ch)
                    a[j]=ch2;
                    else if(a[j]==ch2)
                    a[j]=ch;
                }
                break;
            }
            
        }
        
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends
