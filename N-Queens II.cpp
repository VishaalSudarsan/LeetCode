class Solution {
public:
    class ChessBoard {
        vector<vector<bool>> board;
        public:
        ChessBoard(int n)
        {
            board.resize(n);
            for(int i=0;i<n;i++)
                board[i].resize(n, false);
        }
        void PlaceQueen(int i, int j)
        {
            board[i][j] = true;
        }
        void RemoveQueen(int i, int j)
        {
            board[i][j] = false;
        }
        vector<pair<int,int>> GetAllQueenPositions()
        {
            vector<pair<int,int>> positions;
            for(int i=0;i<board.size();i++)
                for(int j=0;j<board.size();j++)
                    if(board[i][j])
                        positions.push_back(pair<int,int>(i,j));
            return positions;
        }
        bool IsValid()
        {
            vector<pair<int,int>> positions = GetAllQueenPositions();
            for(int i=0;i<positions.size();i++)
                for(int j=i+1;j<positions.size();j++)
                    if(positions[i].first == positions[j].first || positions[i].second == positions[j].second)
                        return false;
                    else if(abs(positions[i].first - positions[j].first) == abs(positions[i].second - positions[j].second))
                        return false;
            return true;
        }
        void Show()
        {
            for(vector<bool> row : (*this).board)
            {
                cout<<endl;
                for(bool cell : row)
                    cout<<int(cell)<<" ";
            }
            cout<<"\n\n";
        }
        vector<string> ConvertToReturnFormat()
        {
            int size = this->board.size();
            vector<string> result;
            for(int i=0;i<size;i++)
            {
                string row;
                for(int j=0;j<size;j++) 
                    if(this->board[i][j])
                        row += "Q";
                    else
                        row += ".";
                result.push_back(row);
            }
            return result;  
        }
    };
    
    void backtrack(ChessBoard board, int row, int col, vector<ChessBoard>& permutations, int& n)
    {
        if(!board.IsValid())
            return;
        if(row == n)
        {
            permutations.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            board.PlaceQueen(row,i);
            backtrack(board, row+1, i+2, permutations, n);
            board.RemoveQueen(row, i);
        }
    }
    
    int totalNQueens(int n) 
    {
        vector<vector<string>> result;
        vector<ChessBoard> permutations;
        ChessBoard board(n);
        backtrack(board, 0, 0, permutations, n);
        for(ChessBoard board : permutations)
            result.push_back(board.ConvertToReturnFormat());
        return result.size();        
    }
};
