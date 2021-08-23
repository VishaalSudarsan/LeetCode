class Solution {
public:
    //idea is to use a dynamic programming approach to solve the problem
    //build a dp array (although not needed for solving the problem it will be useful in understanding
    //the solution) such that dp[i] represents the maximum subarray with nums[i] as the last element of the
    //subarray. since there is only one possible last element in the solution subarray, the sum of the solution
    //subarray must equal the max element in dp array.
    
    //since dp[i] can be computed using dp[i-1] and nums[i], we do not need to store the whole dp array all the time
    //therefore in the below solution we only keep tract of dp[i-1] in the variable previous_elem_sum and we keep
    //updating the maximal sum found so far in max_value. 
    int maxSubArray(vector<int>& nums) {
        int max_value = nums[0], previous_elem_sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > previous_elem_sum + nums[i])//this basically means we want to start the subarray from i
                previous_elem_sum = nums[i];
            else                                    //else condition would mean we are appending elements to the contagious subarray
                previous_elem_sum += nums[i];
            
            if(previous_elem_sum > max_value)
                max_value = previous_elem_sum;      //update the max_value as we see a better maximal subarray 
        }
        
        return max_value;
    }
};
