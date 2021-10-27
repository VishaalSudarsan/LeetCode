//Method 1
class Solution {
public:
    //Just sort the array. Here we use a bubble sort due to it's simplicity
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
    //But there is no need to actually sort the data because we know there are
    //only 3 colors so we just count them and then rewrite them in the correct order
    void sortColors(vector<int>& nums) 
    {
        //initialize the counting map
        array<int, 3> colors = {0,1,2};
        unordered_map<int, int> color_map;
        for(int color : colors)
            color_map[color] = 0;
        
        //count the colors
        for(int elem : nums)
            color_map[elem]++;
        
        //rewrite the nums vector
        int pos = 0;
        for(int color : colors)
            while(color_map[color]--)
                nums[pos++] = color;
    }
};
