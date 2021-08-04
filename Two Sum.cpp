class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indices;
        vector<int> result({-1,-1});
        for(int i=0;i<nums.size();i++)
            indices[nums[i]] = i;
        for(int i=0;i<nums.size();i++)
            if(indices.find(target-nums[i]) != indices.end() && indices[target-nums[i]] != i)
                return(vector<int>({i, indices[target-nums[i]]}));
        return result;
    }
};
