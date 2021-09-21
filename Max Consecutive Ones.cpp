class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        for(int i=1;i<nums.size();i++)
            nums[i] == 0 ? 0 : nums[i] += nums[i-1];
        return *max_element(nums.begin(), nums.end());
    }
};
