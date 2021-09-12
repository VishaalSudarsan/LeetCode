class Solution {
public:
    int tribonacci_func(int n, vector<int>& dp)
    {
        if(dp[n] != -1)
            return dp[n];
        if(dp[n-1] == -1)
            dp[n-1] = tribonacci_func(n-1, dp);
        if(dp[n-2] != -1)
            dp[n-2] = tribonacci_func(n-2, dp);
        if(dp[n-3] != -1)
            dp[n-3] = tribonacci_func(n-3, dp);
        return dp[n-1] + dp[n-2] + dp[n-3];
    }
    int tribonacci(int n) 
    {
        vector<int> dp(n+4, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return tribonacci_func(n, dp);
    }
};
