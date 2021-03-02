class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> unique_candyType(candyType.begin(), candyType.end());
        return min(unique_candyType.size(),candyType.size()/2);
    }
};
