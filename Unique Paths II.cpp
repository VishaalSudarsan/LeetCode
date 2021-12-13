class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0;i<m+1;i++)
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(obstacleGrid[i-1][j-1])
                    dp[i][j] = 0;
                else if(i==1 && j==1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        
        for(vector<int> row : dp)
        {
            cout<<endl;
            for(int elem : row)
                cout<<elem<<" ";
        }
        
        return dp[m][n];
    }
};
