class Solution {
public:   
    int exploreIsland(vector<vector<int>>& grid, vector<vector<int>>& visited, pair<int, int> location, int size = 1)
    {
        if (location.first >= grid.size() || location.first < 0 || location.second >= grid[0].size() || location.second < 0)
            return size-1;

        if (grid[location.first][location.second] == 0)
            return size-1;

        if (visited[location.first][location.second] == 1)
            return size-1;
        else
            visited[location.first][location.second] = 1;

        int down = exploreIsland(grid, visited, make_pair(location.first + 1, location.second));
        int right = exploreIsland(grid, visited, make_pair(location.first, location.second + 1));
        int up = exploreIsland(grid, visited, make_pair(location.first - 1, location.second));
        int left = exploreIsland(grid, visited, make_pair(location.first, location.second - 1));
        int total = down + right + up + left + 1;

        return total;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size(), max_area = INT_MIN, location_area;
        pair<int, int> location;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
            {
                if(visited[i][j]) continue;
                location.first = i;
                location.second = j;
                location_area = exploreIsland(grid, visited, location);
                if (location_area > max_area)
                    max_area = location_area;
            }
        return max_area;
    }
};
