class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int median, moves = 0;
        sort(nums.begin(), nums.end());
        median = nums[nums.size()/2];
        for(int elem : nums)
            moves += abs(elem - median);
        return moves;
    }
};
