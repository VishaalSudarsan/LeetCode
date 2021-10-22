class Solution {
public:
    
    pair<int,int> nextloc(int i, int j, vector<vector<int>>& matrix)
    {
        return(pair<int,int>(j, matrix.size()-1-i));
    }
    
    void rotate(vector<vector<int>>& matrix) 
    {
        int length = matrix.size(), temp1, temp2;
        for(int i=0;i<length/2;i++) 
            for(int j=i;j<length-1-i;j++)
            {
                pair<int, int> next = nextloc(i,j,matrix);
                temp1 = matrix[next.first][next.second];
                matrix[next.first][next.second] = matrix[i][j];
                next = nextloc(next.first, next.second, matrix);
                temp2 = matrix[next.first][next.second];
                matrix[next.first][next.second] = temp1;
                next = nextloc(next.first, next.second, matrix);
                temp1 = matrix[next.first][next.second];
                matrix[next.first][next.second] = temp2;
                next = nextloc(next.first, next.second, matrix);
                matrix[next.first][next.second] = temp1;
            }      
    }
};
