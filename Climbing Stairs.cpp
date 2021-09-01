class Solution {
public:
    int climbStairsInner(int n, vector<int>& dp)
    {
        if(dp[n] > 0)
            return dp[n];
        else
        {
            dp[n] = climbStairsInner(n-1, dp) + climbStairsInner(n-2, dp);
            return dp[n];
        }
    }
    int climbStairs(int n) 
    {
        vector<int> dp(n+2, -1);
        dp[1] = 1;
        dp[2] = 2;
        return climbStairsInner(n, dp);
    }
};
