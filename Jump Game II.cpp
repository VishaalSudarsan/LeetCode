class Solution {
public:   
    int jump(vector<int>& nums) {
    int size = nums.size(), start = 0, end = min(nums[0], size-1), max_pos=-1, count=0;
    if (size == 1) return 0;
    while (end < size )
    {
        while (start <= end)
        {
            if (nums[start] + start > max_pos)
            {
                max_pos = min(nums[start] + start, size-1);
            }
            start++;
        }
        end = max(start, max_pos);
        count++;
    }
    return count;
    }
};
