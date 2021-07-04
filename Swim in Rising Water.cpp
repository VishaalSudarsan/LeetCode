class Solution {
public:
     
    bool isValidNeighbour(pair<int, int> index, vector<vector<int>>& grid)
    {
        if( index.first >= grid.size() || index.first < 0)
            return false;
        if( index.second >= grid.size() || index.second < 0)
            return false;
        return true;
    }
    
    vector<pair<int,int>> getValidNeighbours(pair<int,int> index, vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        vector<pair<int,int>> valid_neighbours;
        array<int, 2> plusminus = {1,-1};
        for(int i=1;i<=2;i++)
            for(int change : plusminus)
            {
                pair<int,int> neighbour1(pair<int,int>(index.first + change, index.second)), neighbour2(pair<int,int>(index.first, index.second + change));
                if(isValidNeighbour(neighbour1, grid) && visited[index.first + change][index.second] == 0)
                    valid_neighbours.push_back(neighbour1);
                if(isValidNeighbour(neighbour2, grid) && visited[index.first][index.second + change] == 0)
                    valid_neighbours.push_back(neighbour2);
            }
        return valid_neighbours;
    }
 
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid.size(), INT_MAX));
        dp[0][0] = 0;
        auto compare = [](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) { return a.second > b.second;};
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, decltype(compare)> next_index_queue(compare);
        pair<pair<int,int>,int> start(pair<pair<int,int>,int>(pair<int,int>(0,0),0));
        next_index_queue.push(start);
        vector<vector<int>> visited(grid.size(),vector<int>(grid.size(),0));
        
        while(visited[grid.size()-1][grid.size()-1] == 0)
        {          
            pair<pair<int,int>,int> current_index = next_index_queue.top();
            visited[current_index.first.first][current_index.first.second] = 1;
            next_index_queue.pop();
            vector<pair<int,int>> valid_neighbours = getValidNeighbours(current_index.first, grid, visited);
            for(pair<int,int> neighbour : valid_neighbours)
            {
                dp[neighbour.first][neighbour.second] = min(dp[neighbour.first][neighbour.second], max({grid[current_index.first.first][current_index.first.second], grid[neighbour.first][neighbour.second], dp[current_index.first.first][current_index.first.second]}));
                pair<pair<int,int>,int> neighbour_index(pair<pair<int,int>,int>(neighbour, grid[neighbour.first][neighbour.second]));
                next_index_queue.push(neighbour_index);
            }
        }
     
        return dp[grid.size()-1][grid.size()-1];
    }
};
