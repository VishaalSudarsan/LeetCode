class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        m--;
        n--;
        vector<vector<int>> dp(m+2, vector<int>(n+2,0));
        dp[m+1][n+1] = 1;
        for(int i=m+1;i>=1;i--)
            for(int j=n+1;j>=1;j--)
                if(i==m+1 && j==n+1)
                    dp[i][j] = 1;
                else if(i==m+1)
                    dp[i][j] = dp[i][j+1];
                else if(j==n+1)
                    dp[i][j] = dp[i+1][j];
                else
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
        return dp[1][1];
    }
};
