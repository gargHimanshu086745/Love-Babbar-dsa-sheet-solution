// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<long int> s;
        int n=x.size();
        if(n%2==1)
        return 0;
        else if(x[0]==123+2 || x[0]==40+1 || x[0]==91+2)
        return 0;
        for(int i=0;i<n;i++)
        {
            if(x[i]==123)
            {   
                int y=int(x[i]+2);
                s.push(y);
            }
            else if(x[i]==40)
            {   
                int y=int(x[i]+1);
                s.push(y);
            }
            else if(x[i]==91 )
            {   
                int y=int(x[i]+2);
                s.push(y);
            }
            else if(s.empty() && (x[i]==123+2 || x[i]==40+1 || x[i]==91+2))
            {
             return 0;   
            }
            else
            {
                int temp=int(x[i]);
                if(s.top()==temp)
                s.pop();
                else
                return 0;
            }
        }
        
        return 1;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
