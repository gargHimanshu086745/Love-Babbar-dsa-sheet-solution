// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    
    stack<char> s;
    
    char *start=S;
    for(int i=0;i<len;i++)
    {
        s.push(*S);
        S++;
    }
    
    S=start;
    
    for(int i=0;i<len;i++)
    {
        char top=s.top();
        s.pop();
        *S=top;
        S++;
    }
    return start;
}
