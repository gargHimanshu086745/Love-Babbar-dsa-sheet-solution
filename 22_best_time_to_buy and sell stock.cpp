class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        int profit=0;
        if(l==0 || l==1)
            return 0;
        
        int max=prices[l-1];
        for(int i=l-2;i>=0;i--)
        {
            if(max-prices[i]>=0 && max-prices[i]>profit)
            {
                profit=max-prices[i];
            }
            if(prices[i]>max)
                max=prices[i];
        }
        if(profit>0)
            return profit;
        else
            return 0;
    }
};
