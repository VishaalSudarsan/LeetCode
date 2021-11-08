class Solution {
public:
    
    int numTreesInner(int n, vector<int>& dp)
    {
        if(dp[n] != -1)
            return dp[n];
        else
        {
            int sum=0;
            for(int i=0;i<n;i++)
                sum += numTreesInner(i, dp) * numTreesInner(n-i-1, dp);
            dp[n]=sum;
        }
        return 0;
    }
    int numTrees(int n) 
    {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=0;i<=n;i++)
            numTreesInner(i, dp);
        
        return dp[n];
    }
};
