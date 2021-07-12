class Solution {
public:
bool canJump(vector<int>& nums) {
    int size = nums.size();
    int last_true_pos = size - 1;
    for (int i = size - 2; i > 0; i--)
        if (nums[i] + i >= last_true_pos)
            last_true_pos = i;
    return nums[0] >= last_true_pos;
}
};
