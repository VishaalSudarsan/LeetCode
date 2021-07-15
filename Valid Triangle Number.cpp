class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        vector<int>::iterator pos;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0) continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j] == 0) continue;
                pos = lower_bound(nums.begin()+j, nums.end(), nums[i]+nums[j]);
                count += distance(nums.begin(), pos) - j - 1;
            }
        }
        return count;
    }
};
