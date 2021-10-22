class Solution {
public:
    //This is the function that tells what should be the next coordinate for a given index i,j
    //note that (0,0) -> (0,n-1) -> (n-1,n-1) -> (n-1,0)
    //similarly (0,1) -> (1,n-1) -> (n-1,n-2) -> (n-2, 0)
    //the patern here is that the jth coordinate becomes the new ith coordinate 
    //and the new jth coordinate is n-1 - i
    pair<int,int> nextloc(int i, int j, vector<vector<int>>& matrix)
    {
        return(pair<int,int>(j, matrix.size()-1-i));
    }
    
    //This function rotates the matrix layer-by-layer
    //i.e first the top most square boundary is rotated and then the 2nd layer is rotated
    //and so on
    void rotate(vector<vector<int>>& matrix) 
    {
        int length = matrix.size(), temp1, temp2;
        for(int i=0;i<length/2;i++) //think of this as the diagonal pivot, we only need this to be going from top-left to the center
            for(int j=i;j<length-1-i;j++)//each layer is smaller than the previous one by a factor of 2 (1 from both sides)
            {
                //the following chunk of code is just to rotate each element by a full cycle
                //it would need 4 change of numbers in indices hence 4 calls to nextloc function
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
