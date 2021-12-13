class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(),0), size = nums.size();
        if(sum%2 != 0)
            return false;
        int val = sum/2;
        vector<vector<int>> dp(size+1, vector<int>(val+1, 0));
        for(int i=0;i<size+1;i++)
            for(int j=0;j<val+1;j++)
            {
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 0;
                else if(j>=nums[i-1])
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
                if(j==val && dp[i][j])
                    return true;
            }
        return false;
    }
};
