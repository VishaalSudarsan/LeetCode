//Method1
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


//Method2
class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> dp(n+2, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        if(n<=2)
            return dp[n];
        else
        {
            for(int i=3;i<n+1;i++)
                dp[i] = dp[i-1] + dp[i-2];
            return dp[n];
        }
    }
};

