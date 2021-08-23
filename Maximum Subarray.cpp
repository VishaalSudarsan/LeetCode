class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_value = nums[0], previous_elem_sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > previous_elem_sum + nums[i])
                previous_elem_sum = nums[i];
            else
                previous_elem_sum += nums[i];
            
            if(previous_elem_sum > max_value)
                max_value = previous_elem_sum;
        }
        
        return max_value;
    }
};
