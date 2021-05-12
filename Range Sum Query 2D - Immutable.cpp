class NumMatrix {
    vector<vector<int>> summatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size(), columns = matrix[0].size();
        for(int i=0;i<rows+1;i++)
        {
            vector<int> temp;
            for(int j=0;j<columns+1;j++)
            {
                if(i==0||j==0)
                    temp.push_back(0);
                else
                    temp.push_back(summatrix[i-1][j] + temp[j-1] - summatrix[i-1][j-1] + matrix[i-1][j-1]);
            }
            summatrix.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return summatrix[row2+1][col2+1] - summatrix[row2+1][col1] - summatrix[row1][col2+1] + summatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
