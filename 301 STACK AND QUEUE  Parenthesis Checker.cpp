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
        stack<char> s;
        // s.push(x[0]);
        char p=x[5];
        // int top=s.top()
        // if(s.top()=='{' && x[5]=='}')
        // {
        //     cout<<"dsv";
        //     s.pop();
        // }
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='('||x[i]=='{'||x[i]=='[')
                s.push(x[i]);
            else if(s.empty() &&(x[i]==')' || x[i]=='}' || x[i]==']'))
            return false;
            else
            {
                if(s.top()=='(' && x[i]==')')
                s.pop();
                else if(s.top()=='{' && x[i]=='}')
                s.pop();
                else if(s.top()=='[' && x[i]==']')
                s.pop();
                else
                return false;
            }
            
            
        }
        if(s.empty())
        return true;
        else
        return false;
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
