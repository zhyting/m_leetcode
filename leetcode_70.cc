class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0)
        {
            return 0;
        }
        if(1 == n || 2 == n)
        {
            return n;
        }
        int dp[n];
        dp[0]=1;
        dp[1]=2;
        for(int i = 2;i < n;++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};