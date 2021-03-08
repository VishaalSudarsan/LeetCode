class Solution {
public:
    vector<pair<int,int>> neighbours(pair<int,int> index, int &rows, int &columns)
    {
        vector<pair<int,int>> result;
        vector<int> plusminus({1,-1});
        for(int elem : plusminus)
        {
            if(elem+index.first >= 0 && elem+index.first <= rows-1)
                result.push_back(pair<int,int>(index.first+elem, index.second));
            if(elem+index.second >= 0 && elem+index.second <= columns-1)
                result.push_back(pair<int,int>(index.first, index.second+elem));
        }
        return result;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), columns = heights[0].size();
        vector<vector<int>> distance(rows, vector<int>(columns, INT_MAX/2));
        distance[0][0]=0;
        auto comp = [&](const array<int, 3> &p1, const array<int, 3> &p2) { return p1[0] >= p2[0]; };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> queue(comp);
        for(int i=0;i<rows;i++)
            for(int j=0;j<columns;j++)
                queue.push({distance[i][j],i,j});
       
        while(queue.size())
        {           
            array<int,3> minelement = queue.top();
            queue.pop();
            if(minelement[1]==rows-1 && minelement[2]==columns-1) break;
            if(minelement[0]>distance[minelement[1]][minelement[2]]) continue;
            pair<int,int> nearest_index({minelement[1],minelement[2]});
            vector<pair<int,int>> reachable_indexes = neighbours(nearest_index, rows, columns);
            for(pair<int,int> index : reachable_indexes)
            {
                int new_effort = max(distance[nearest_index.first][nearest_index.second],abs(heights[nearest_index.first][nearest_index.second] - heights[index.first][index.second]));
                if(new_effort < distance[index.first][index.second])
                {
                     distance[index.first][index.second] = max(distance[nearest_index.first][nearest_index.second], new_effort);
                    queue.push({new_effort,index.first,index.second});
                }
            }
        }
        return distance[rows-1][columns-1];
        
    }
};
