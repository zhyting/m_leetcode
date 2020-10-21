//动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(0 == prices.size())
        {
            return 0;
        }
        vector<int> dp(prices.size());
        int prev = prices[0];
        dp[0] = 0;

        for(int i = 1; i < prices.size();++i)
        {
            dp[i] = max(dp[i-1],prices[i]-prev);
            if(prev > prices[i])
            {
                prev = prices[i];
            }
        }
        return dp[prices.size()-1];
    }
};