class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int tempmax = 1, maxlength = 1;
        vector<int> dp;
        dp.push_back(1);
        for(int i=1;i<nums.size();i++)
        {
            tempmax = 1;
            for(int j=i-1;j>=0;j--)           
                if(nums[i] > nums[j] && tempmax < dp[j] + 1)
                    tempmax = dp[j] + 1;
            dp.push_back(tempmax);
            if(maxlength < tempmax) maxlength = tempmax;
        }
        return maxlength;
    }
};
