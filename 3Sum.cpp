class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        //if array size is less than 3 then there are no possibilites
        if(nums.size() < 3)
            return vector<vector<int>>({});
        int left, right;
        
        //sort the array to build an efficient algorithm
        //we start with iterating through the sorted array using a for loop
        //the num[i] would be the first element of each zero-triplet
        //we would scan for the remaining two elements in the indices i+1 to n-1
        //we would have two pointers in i+1 and n-1 respectively and would check if the
        //sum of the triplet is zero, if yes store it, if not then see if the sum is 
        //greater or less than zero. if greater then we need to decrement the right pointer
        //if lesser than zero we need to increment the left pointer so that the sum is closer to 0
        sort(nums.begin(), nums.end());
        vector<vector<int>> result_vec;
        for(int i=0;i<nums.size()-2;i++)
        {
            //to avoid duplicate triplets, since nums[i] represents the first element of the zero-triplet
            //we would skip the same nums[i] to avoid same triplets generated from a single nums[i]
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            left = i+1;
            right = nums.size()-1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] == 0)
                {
                    result_vec.push_back({nums[i], nums[left], nums[right]});
                    
                    //both the while statements are to avoid duplicate zero-triplets
                    //if the adjecent elements are the same then the algorithm will end up having repeated
                    //triplets due to the duplicate elements so we jump the duplicate elements 
                    //"only after we find a zero-triplet" to avoid storing duplicate zero-triplets
                    while((left < right) && (nums[right] == nums[right-1]))
                        right--;
                    while((left < right) && (nums[left] == nums[left+1]))
                        left++;
                    right--;
                    left++;
                }
                if(nums[i] + nums[left] + nums[right] > 0)
                    right--;
                if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
            }    
        }
        return result_vec;
    }
};
