class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int sell = INT_MAX;
        for(int i=0; i < prices.size(); i++){
            sell = min(sell,prices[i]);
            int temp = prices[i]-sell;
            profit = max(profit,temp);
        }
        return profit;
    }
};
