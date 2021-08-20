class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) 
    {
        vector<vector<int>> attacking_queens;
        vector<vector<int>> queen_map(8, vector<int>(8, 0));
        for(vector<int> pos : queens)
            queen_map[pos[0]][pos[1]] = 1;
        
        /*for(vector<int> row : queen_map)
        {
            cout<<endl;
            for(int elem : row)
                cout<<elem<<" ";
        }*/

        for(int i=king[0], j=king[1]; i<8;i++)
            if(queen_map[i][j])
            {
                attacking_queens.push_back(vector<int>({i,j}));
                break;
            }
        
        
        for(int i=king[0], j=king[1];i>=0;i--)
            if(queen_map[i][j])
            {
                attacking_queens.push_back(vector<int>({i,j}));
                break;
            }
        
        for(int i=king[0], j=king[1];j<8;j++)
            if(queen_map[i][j])
            {
                attacking_queens.push_back(vector<int>({i,j}));
                break;
            }
        
        for(int i=king[0], j=king[1];j>=0;j--)
            if(queen_map[i][j])
            {
                attacking_queens.push_back(vector<int>({i,j}));
                break;
            }
        
        for(int i=king[0], j=king[1];j>=0 && i>=0;j--, i--)
            if(queen_map[i][j])
            {
                attacking_queens.push_back(vector<int>({i,j}));
                break;
            }
        
        for(int i=king[0], j=king[1];j<8 && i>=0;j++, i--)
            if(queen_map[i][j])
            {
                attacking_queens.push_back(vector<int>({i,j}));
                break;
            }
        
        for(int i=king[0], j=king[1];j<8 && i<8;j++, i++)
            if(queen_map[i][j])
            {
                attacking_queens.push_back(vector<int>({i,j}));
                break;
            }
        
        for(int i=king[0], j=king[1];j>=0 && i<8;j--, i++)
            if(queen_map[i][j])
            {
                attacking_queens.push_back(vector<int>({i,j}));
                break;
            }
        
        return attacking_queens;
    }   
};
