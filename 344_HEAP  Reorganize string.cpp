class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        string result;
        priority_queue<pair<int,char>> pq;
        
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto it: mp){
            pq.push(make_pair(it.second, it.first));
        }
        
        while(pq.size() > 1) {
            char mostFreq = pq.top().second;
            pq.pop();
            char nextFreq = pq.top().second;
            pq.pop();
            
            result+= mostFreq;
            result+= nextFreq;
            
            if(mp[mostFreq] - 1 > 0){
                mp[mostFreq]--;
                pq.push(make_pair(mp[mostFreq], mostFreq));
            }
            
            if(mp[nextFreq] -1 > 0){
                mp[nextFreq]--;
                pq.push(make_pair(mp[nextFreq], nextFreq));
            }
        }
        
        if(pq.size()){
            char freq = pq.top().second;
            
            if(mp[freq] > 1)
                return "";
            
            else
                result+=freq;
        }
        return result;
    }
};
