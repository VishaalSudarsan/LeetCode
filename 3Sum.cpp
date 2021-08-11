class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size() < 3)
            return vector<vector<int>>({});
        int left, right;
        sort(nums.begin(), nums.end());
        vector<vector<int>> result_vec;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            left = i+1;
            right = nums.size()-1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] == 0)
                {
                    result_vec.push_back({nums[i], nums[left], nums[right]});
                    while((left < right) && (nums[right] == nums[right-1]))
                        right--;
                    while((left < right) && (nums[left] == nums[left+1]))
                        left++;
                    right--;
                    left++;
                }
                if(nums[i] + nums[left] + nums[right] > 0)
                    right--;
                if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
            }    
        }
        return result_vec;
    }
};
