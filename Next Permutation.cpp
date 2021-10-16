class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int pos = nums.size()-2;
        while(pos >= 0 && nums[pos] >= nums[pos+1]) pos--;
        if(pos == -1) 
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        vector<int>::iterator lb = lower_bound(nums.begin()+pos+1, nums.end(), nums[pos], greater<int>());
        reverse(lb, nums.end());
        reverse(nums.begin()+pos+1, lb-1);
        rotate(nums.begin()+pos, lb-1, nums.end());
    }
};
