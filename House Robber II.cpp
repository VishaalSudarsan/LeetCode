class Solution {
public:
    int rob_straight(vector<int> nums)
    {
        int size = nums.size();
        if(size == 1)
            return nums[0];
        if(size == 2)
            return max(nums[1], nums[0]);

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        for(int i=3;i<size;i++)
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]); 
        return *max_element(dp.begin(), dp.end());        
    }
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin()+1, nums.end()), nums2(nums.begin(), nums.end()-1);
        return max(rob_straight(nums1), rob_straight(nums2));
    }
};
