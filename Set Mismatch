class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, bool> stored_nums;
        int missing, repeated, sum=0, size = nums.size(), expected_sum = size*(size+1)/2;
        for(int num : nums)
        {
            stored_nums[num] = true;
            sum += num;
        }
        for(int i=1;i<=size;i++)
            if(stored_nums.find(i) == stored_nums.end())
            {
                missing = i;
                break;
            }

        repeated = sum - expected_sum + missing;
        vector<int> result({repeated, missing});
        
        return result;
    }
};
