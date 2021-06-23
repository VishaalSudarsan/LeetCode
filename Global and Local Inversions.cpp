class Solution {
public:
        bool isIdealPermutation(vector<int>& nums) {
                
        //The number of global inversions is always greater than or equal to the number of local inversions.
        //Therefore, all we need to do is that find a pair (i,j) such that nums[i] > nums[j] and i != j-1 and j > i 
        //This is because if i = j - 1 then it is a local inversion (and hence a global inversion too)
        //However if i != j - 1 then it is a global inversion only
        //We further use the fact that the input of the function is just a permutation of the set (0,1,2,...nums.size()-1)
        //This implies if the number x is not in the index x then the number in the index x say y must be in some relationship with x
        //Either both global and local inversion or just global inversion. Note that if the number x is in the index x+1 or x-1 then
        //it is in local inversion with y, otherwise it is in global inversion with y. So all we need is one element x which is not in
        //the index x, x+1, x-1. If we have such an element it would be purely a global inversion and therefore the number of global 
        //inversion would not equal the number of local inversion.
                
        //Time Complexity : O(n)
        //Space Complexity : O(1)
                
                
        for (int i = 0; i < nums.size(); i++)
            if (abs(nums[i]-i) > 1)
                return false;

        return true;
    }
};
