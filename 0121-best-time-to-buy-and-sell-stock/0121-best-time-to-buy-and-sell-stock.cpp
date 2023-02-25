class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxi = -1;
        for(int i =prices.size()-1; i>=0; i-- ) {
            maxi = max(maxi,prices[i]);
            profit= max(profit, maxi-prices[i]);
        }
        return profit;
    }
};