/*
1   "1"
2     "11"   1 ki  count 1 time  ye uper bali value se lete  hai and follow this ordered
3       "21"   1 ki count 2 time
4     "1211"   1 time 2 ki count and 1 time 1 ki count 
5       "111221"   1 time 1 ki count 1time 2 ki count 2 time 1 ki count
*/
class Solution {
public:
    string countAndSay(int n) {
            if(n==1) return "1";
            if(n==2) return "11";
        
            string s = "11";
          
          for(int i=3;i<=n;i++)
          {
              string t ="";
              s = s+"$";
              int cnt =1;
              for(int j = 1;j<s.size();j++)
              {
                  if(s[j-1] != s[j])
                  {
                      t = t+to_string(cnt);
                      t = t+ s[j-1];
                      cnt =1;
                  }
                  else
                     cnt++;
              }
               
              s = t;
          }
        
        return s;
              
         
    }
};
