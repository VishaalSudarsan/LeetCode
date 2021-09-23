class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int set_size;
        set<set<int>> power_set({set<int>({})});
        do
        {
            set_size = power_set.size();
            set<set<int>> temp_power_set;
            for(int elem : nums)
                for(set<int> set : power_set)
                {
                    set.insert(elem);
                    temp_power_set.insert(set);
                }
            power_set = temp_power_set;
        }while(set_size != power_set.size());
        
        vector<vector<int>> result;
        for(set<int> set : power_set)
            result.push_back(vector<int>(set.begin(), set.end()));
        
        result.push_back(vector<int>({}));
        return result;
    }
};
