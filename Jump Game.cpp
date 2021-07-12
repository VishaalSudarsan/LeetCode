class Solution {
public:
bool canJump(vector<int>& nums) {
    //The idea is to check from the last element
    //Check if you can reach from the second last element to
    //the last element ? If yes check if the second last element
    //can be reached from third last element. If No then check if
    //the last element can be reached from the third last element
    //Do this iteratively until you've reached the first index.
    
    int size = nums.size();
    int last_true_pos = size - 1;
    for (int i = size - 2; i > 0; i--)
        if (nums[i] + i >= last_true_pos)
            last_true_pos = i;
    return nums[0] >= last_true_pos;
}
};
