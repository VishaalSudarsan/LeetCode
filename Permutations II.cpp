class Solution {
public:
    void permuteInner(vector<int> nums, vector<vector<int>>& allpermutations, int pos = 0)
    {
        if(pos == nums.size()-1)
        {
            allpermutations.push_back(nums);
            return;
        }
        else
        {
            for(int i=pos;i<nums.size();i++)
            {
                if(nums[i] == nums[pos] && i != pos)
                    continue;
                else
                {
                    swap(nums[i], nums[pos]);
                    permuteInner(nums, allpermutations, pos+1);
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allpermutations;
        permuteInner(nums, allpermutations);
        return allpermutations;
    }
};
