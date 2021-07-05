class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if((mat.size() == r && mat[0].size() == c) || (mat.size()*mat[0].size() != r*c))
            return mat;
        vector<vector<int>> new_matrix;
        vector<int> temp_row;
        for(vector<int> row : mat)
            for(int elem : row)
            {
                temp_row.push_back(elem);
                if(temp_row.size() == c)
                {
                    new_matrix.push_back(temp_row);
                    temp_row.clear();
                }
            }
        return new_matrix;
    }
};
