class Solution {
public:
    void generate_permutations(vector<int> nums, int pos, vector<vector<int>>& permutations)
    {
        //add the permutation to the return variable if we reached the leaf node
        if(pos == nums.size()-1)
            permutations.push_back(nums);
        for(int i=pos;i<nums.size();i++)
        {
            //swap the element and run the algorithm recursively for arr[pos+1:n-1] 
            swap(nums[i], nums[pos]);
            generate_permutations(nums, pos+1, permutations);
            //swap the elements back so that the next swap in the loop makes sense
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        //create a inner function to calculate all permutations starting from
        //pos 0. we create a tree where every node represents a permutation.
        //we start with the given array as the root node and then create n childs
        //where each child is a permutation of the array where every element is
        // exchanged with the first element of the array. For example : if the array is 
        //[1,2,3,4] then the children of this root would be [1,2,3,4],[2,1,3,4],[3,2,1,4],
        //[4,2,3,1]. Now all possibilities for the first place in the array has been obtained
        //i.e if we solve for arr[1:n-1] for each of the child and just append arr[0] to the
        //solution then we get the answer for arr[0:n-1]. therefore we just recursively implement
        //this until we reach the bottom of the tree. the nodes in the bottom of the tree would be 
        //the list of all permutations possible. 
    
        vector<vector<int>> permutations;
        generate_permutations(nums, 0, permutations);
        return permutations;
    }
};
