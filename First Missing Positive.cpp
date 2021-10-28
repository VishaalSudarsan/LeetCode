class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int size = nums.size(), missing_positive;
        if(size == 1)
        {
            if(nums[0] == 1)
                return 2;
            else
                return 1;
        }
        
        for(int i=0;i<size;i++)
        {
            if(i == nums[i]) continue;
            
            try
            {
                if(nums.at(i) != nums.at(nums.at(i)))
                {
                    swap(nums.at(i), nums.at(nums.at(i)));
                    i--;
                }
            }
            catch(...)
            {
                continue;
            }
        }
        

        for(int i=1;i<size;i++)
            if(i != nums[i])
            {
                missing_positive = i;
                return missing_positive;
            }
        
        if(nums[0] == size)
            missing_positive = size+1;
        else    
            missing_positive = nums[size-1]+1;
        return missing_positive;
    }
};
