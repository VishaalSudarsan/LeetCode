class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>::iterator index;
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            index = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(index == dp.end())
                dp.push_back(nums[i]);
            else if(nums[i] < *index)
                *index = nums[i];
        }
        return dp.size();
    }
};
