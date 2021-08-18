class Solution {
public:
    void generate_permutations(vector<int> nums, int pos, vector<vector<int>>& permutations)
    {
        if(pos == nums.size()-1)
            permutations.push_back(nums);
        for(int i=pos;i<nums.size();i++)
        {
            swap(nums[i], nums[pos]);
            generate_permutations(nums, pos+1, permutations);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> permutations;
        generate_permutations(nums, 0, permutations);
        return permutations;
    }
};
