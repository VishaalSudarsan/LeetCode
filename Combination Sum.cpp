class Solution {
public:
    set<vector<int>> allsums;
    void combinationSumInner(vector<int>& candidates, int target, vector<int> sum)
    {
        if(target < 0)
            return;
        if(target == 0)
        {
            sort(sum.begin(), sum.end());
            allsums.insert(sum);
        }
        else
        {
            for(int elem : candidates)
            {
                sum.push_back(elem);
                combinationSumInner(candidates, target - elem, sum);
                sum.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> sum;
        combinationSumInner(candidates, target, sum);
        return vector<vector<int>>(allsums.begin(), allsums.end());
    }
};
