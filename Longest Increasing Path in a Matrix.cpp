class Solution {
public:
    bool IsValidPath(pair<int, int>& source, pair<int, int>& new_source, vector<vector<int>>& matrix)
    {
        if(matrix[new_source.first][new_source.second] > matrix[source.first][source.second])
            return true;
        else
            return false;
    }
    bool IsValidSource(pair<int, int>& source, vector<vector<int>>& matrix)
    {
        int breadth = matrix.size();
        int length  = matrix[0].size();
        
        if(source.first<breadth && source.first >= 0 && source.second < length && source.second >= 0)
            return true;
        else
            return false;
    }
    int FindLongestPathFromSource(vector<vector<int>>& matrix, pair<int, int> source, vector<vector<int>>& dp)
    {
        
        if(dp[source.first][source.second] != -1)
            return dp[source.first][source.second];
        pair<int, int> up(source.first-1, source.second), down(source.first+1, source.second), left(source.first, source.second-1), right(source.first, source.second+1);
        vector<pair<int, int>> neighbours = {up, down, left, right};
        vector<int> paths;
        for(pair<int, int> new_source : neighbours)
        {
            if(IsValidSource(new_source, matrix) && IsValidPath(source, new_source, matrix))
                paths.push_back(FindLongestPathFromSource(matrix, new_source, dp));
            else
                paths.push_back(0);
        }
        dp[source.first][source.second] = *max_element(paths.begin(), paths.end()) + 1;
        return dp[source.first][source.second];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int breadth = matrix.size();
        int length  = matrix[0].size();
        vector<vector<int>> dp(breadth, vector<int>(length, -1));
        vector<int> all_paths;
        for(int i=0;i<breadth;i++)
            for(int j=0;j<length;j++)
            {
                pair<int, int> source(i,j);
                all_paths.push_back(FindLongestPathFromSource(matrix, source, dp));
            }
        return *max_element(all_paths.begin(), all_paths.end());
    }
};
