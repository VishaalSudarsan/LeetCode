class Solution {
public:
    int trap(vector<int>& height) 
    {
        int size = height.size(), left_wall = height[0], right_wall = height[size-1];
        vector<int> left_water(size, 0), right_water(size, 0), min_water;
        for(int i=1;i<size;i++)
        {
            if(height[i] > left_wall)
                left_wall = height[i];
            else
                left_water[i] = left_wall - height[i];
        }
        for(int i=size-2;i>=0;i--)
        {
            if(height[i] > right_wall)
                right_wall = height[i];
            else
                right_water[i] = right_wall - height[i];
        }
        for(int i=0;i<size;i++)
            min_water.push_back(min(left_water[i], right_water[i]));
        
        return accumulate(min_water.begin(), min_water.end(), 0);
    }
};
