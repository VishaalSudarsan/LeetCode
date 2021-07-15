class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0, left, right;
        sort(nums.begin(), nums.end());
        for(int pos=nums.size()-1;pos>=0;pos--)
        {
            left = 0;
            right = pos-1;
            while(right > left)
            {
                if(nums[left] + nums[right] > nums[pos])
                {
                    count += right - left;
                    right--;
                }
                else
                    left++;
            }
        }
        return count;
    }
};
