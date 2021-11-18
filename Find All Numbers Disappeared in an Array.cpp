class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int size = nums.size();
        vector<bool> store(size+1, false);
        vector<int> missing;
        for(int elem : nums)
            store[elem] = true;
        for(int i=1;i<size+1;i++)
            if(!store[i])
                missing.push_back(i);
        
        return missing;
    }
};
