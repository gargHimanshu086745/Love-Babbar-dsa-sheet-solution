class Solution {
public:
     // int findRemovals(string s);
    void solve(string s, vector<string> &ans,unordered_map<string,bool> &mp,int removals)
    {
        if(mp[s])
            return;
        mp[s]=true;
        
        if(removals==0)
        {
            int removals_needed=findRemovals(s);
            if(removals_needed ==0)
                ans.push_back(s);
            
            return;
        }
        
        for(int i=0;i<s.length();i++)
        {
            string leftPart=s.substr(0,i);
            string rightPart=s.substr(i+1);
            string join=leftPart + rightPart;
            solve(join,ans,mp,removals-1);
        }
    }
    
    int findRemovals(string s)
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        
        return st.size();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_map<string,bool>mp;
        int min_removals=findRemovals(s);
        solve(s,ans,mp,min_removals);
        string temp;
        
        
        
        return ans;
    }
};
