class Solution {
public:
    //idea is to start with the input string and then exchange the first element with each of the element
    //and solve the problem with the newly created string
    //this creates a tree structure where the leaf nodes contain all the possible combinations
    void permuteInner(vector<int> nums, vector<vector<int>>& allpermutations, int pos = 0)
    {
        if(pos == nums.size()-1)
        {
            allpermutations.push_back(nums);//store a combination if reached 
            return;
        }
        else
        {
            for(int i=pos;i<nums.size();i++)
            {
                if(nums[i] == nums[pos] && i != pos) //if the element and pivot is same then exchanging them and creating a new branch in the tree
                    continue;                        //would create duplicacy
                else
                {
                    swap(nums[i], nums[pos]); //swap all unequal elements with the pivot element in pos position
                    permuteInner(nums, allpermutations, pos+1); //and create a new branch in the tree
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allpermutations;
        permuteInner(nums, allpermutations);
        return allpermutations;
    }
};
