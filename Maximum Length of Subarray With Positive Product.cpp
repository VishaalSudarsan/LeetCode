class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> positive(size, 0), negative(size, 0);
        if(nums[0] > 0)
            positive[0] = 1;
        if(nums[0] < 0)
            negative[0] = 1;
        
        for(int i=1;i<size;i++)
        {
            if(nums[i] > 0)
            {
                positive[i] = positive[i-1] + 1;
                negative[i-1] == 0 ? negative[i] = 0 : negative[i] = negative[i-1] + 1;
            }
            if(nums[i] < 0)
            {
                negative[i-1] == 0 ? positive[i] = 0 : positive[i] = negative[i-1] + 1;
                negative[i] = positive[i-1] + 1;
            }
        }
        
        return *max_element(positive.begin(), positive.end());
    }
};
