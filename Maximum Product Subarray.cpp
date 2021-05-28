class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size(), max_prod = INT_MIN, temp_prod = 1;
        for(int i=0;i<size;i++)
        {
            temp_prod = 1;
            for(int j=i;j<size;j++)            {
                temp_prod *= nums[j];
                if(temp_prod > max_prod)
                    max_prod = temp_prod;
            }
        }
        return max_prod;
    }
};
