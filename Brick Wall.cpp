class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int wallheight = wall.size();
        int index =0, max_frequency = 0;
        unordered_map<int,int> index_frequency;
        
        for(vector<int> vec: wall)
        {
            index = 0;
            for(int i=0;i<vec.size()-1;i++)
            {
                index += vec[i];
                if(index_frequency.find(index) != index_frequency.end())
                    index_frequency.at(index) +=1;
                else
                    index_frequency[index] = 1;
                max_frequency = max(max_frequency, index_frequency[index]);
            }

        }
        
        return wallheight - max_frequency;

    }
};
