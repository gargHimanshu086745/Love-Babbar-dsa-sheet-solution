// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

struct node{
  node *child[26];

  bool isend;
  node(){
      for(int i=0;i<26;i++)child[i]=NULL;
    
      isend=false;
  }
};

void insert(node *root,string &s,int in,unordered_map<node*,vector<int>>&mp){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(root->child[s[i]-'a'])root=root->child[s[i]-'a'];
        else{
            root->child[s[i]-'a']= new node();
            root=root->child[s[i]-'a'];
        }
    }
    root->isend=true;
    mp[root].push_back(in);
}

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        
       node *root= new node();
       unordered_map<node*,vector<int>> mp;
       for(int i=0;i<string_list.size();i++)
       {
           string temp=string_list[i];
           sort(temp.begin(),temp.end());
           insert(root,temp,i,mp);
       }
       int n=mp.size();
       vector<vector<string>>ans;
       int i=0;
       
       vector<string>temp;
       
       for(auto it:mp){
           temp.clear();
           for(auto to:it.second)temp.push_back(string_list[to]);
           ans.push_back(temp);
       }
       return ans;

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
