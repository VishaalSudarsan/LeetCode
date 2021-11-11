class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        for(int i=1;i<nums.size();i++)
            nums[i] += nums[i-1];
        
        int result = -1*(*min_element(nums.begin(), nums.end()));
        if(result < 0) result = 0;
        
        return result + 1;
    }
};
