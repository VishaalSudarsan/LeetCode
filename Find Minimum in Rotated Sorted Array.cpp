class Solution {
public:
    int findMin(vector<int>& nums) {

        int size = nums.size();

        if(size == 1)
            return nums[0];
        if(size == 2)
            return min(nums[0], nums[1]);
        if(nums[0] < nums[size-1])
            return nums[0];
        if(nums[size-1] < nums[size-2])
            return nums[size-1];
        
        int start = 0, end = size-1, mid = (start+end)/2;
        while(!(nums[max(mid-1,0)] >= nums[mid] && nums[min(mid+1,size-1)] >= nums[mid]))
        {
           if(nums[mid] >= nums[0])
               start = mid+1;
            else
                end = mid-1;
            mid = (start+end)/2;
        }
        return nums[mid];
    }
};
