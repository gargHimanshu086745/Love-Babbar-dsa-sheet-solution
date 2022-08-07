class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for(auto edg:flights){
            int from = edg[0];
            int to = edg[1];
            int price = edg[2];
            
            graph[from].push_back({to, price});
        }
        
        
        priority_queue< tuple <int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        
        vector<int> costs(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        
        costs[src] = 0;
        stops[src] = 0;
        
        // currCost, currNode, currStop
        
        pq.push({0, src, 0});
        
        
        while(!pq.empty())
        {
            
            auto [currCost, currNode, currStop] = pq.top();
            pq.pop();
            
            if(currNode == dst) return currCost;
            
            if(currStop == k+1) continue;
            
            
            for(auto neighbor:graph[currNode])
            {
                
                int currNeighbor = neighbor.first;
                int currNeighborCost = neighbor.second;
                
                int newCost = currCost + currNeighborCost;
                int newStop = 1 + currStop;
                
                if(newCost < costs[currNeighbor] || newStop < stops[currNeighbor]){
                    costs[currNeighbor] = newCost;
                    stops[currNeighbor] = newStop;
                    
                    pq.push({newCost, currNeighbor, newStop});
                }                
                
            }
        }
        return -1;
    }
};
