//Method 1
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                if(nums[i]>nums[j])
                    swap(nums[i],nums[j]);
    }
};

//Method2
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        array<int, 3> colors = {0,1,2};
        unordered_map<int, int> color_map;
        for(int color : colors)
            color_map[color] = 0;
        
        for(int elem : nums)
            color_map[elem]++;
        
        int pos = 0;
        for(int color : colors)
            while(color_map[color]--)
                nums[pos++] = color;
    }
};
