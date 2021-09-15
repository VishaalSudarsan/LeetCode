class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        vector<int> frequency(*max_element(nums.begin(), nums.end())+1, 0);
        for(int elem : nums) frequency[elem]++;
        int size = frequency.size();
        if(size == 2) return nums[0]*frequency[nums[0]];
        vector<int> dp(size, 0), max_dp(size, 0);
        dp[1] = 1*frequency[1];
        dp[2] = 2*frequency[2];
        max_dp[1] = dp[1];
        max_dp[2] = max(dp[1], dp[2]);
        for(int i=3;i<size;i++)
        {
            dp[i] = max_dp[i-2] + i*frequency[i];
            max_dp[i] = max(max_dp[i-1], dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }   
};
