class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int l=s.size(); 
        for(int i=0;i<l/2;i++)
        {
            temp=s[l-1-i];
            s[l-1-i]=s[i];
            s[i]=temp;
        }
        
    }
};
