class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0, left, right;
        
        //sort the number so that we don't need to check all possibilities
        //such as x+y>z, x+z>y, z+y>x because if x<y<z then x+y>z implies
        //the remaining two inequalitites as z>x and z>y
        sort(nums.begin(), nums.end());
        
        //start from the end (pos), now fix 2 iterators (left and right) running
        //between 0 and pos towards each other. the main idea is that if 
        //nums[left] + nums[right] > nums[pos] then 
        //nums[index] + nums[right] > nums[pos] is true for all index between
        //left and right. also note that if nums[left] + nums[right] is LESS than
        //nums[pos] then nums[left] + nums[index] < nums[pos] is true for all index
        //between left and right. therefore, when nums[left] + nums[right] < nums[pos]
        //we increment left by one and check again. otherwise, if nums[left] + nums[right]
        // > nums[pos] then we increment count by right - left and then decrement right
        //to check for the next combination. note that for any pos the number of moves made
        //by both left and right added together is never greater than pos. hence the time
        //complexity is O(n^2).
        for(int pos=nums.size()-1;pos>=0;pos--)
        {
            left = 0;
            right = pos-1;
            while(right > left)
            {
                if(nums[left] + nums[right] > nums[pos])
                {
                    count += right - left;
                    right--;
                }
                else
                    left++;
            }
        }
        return count;
    }
};
