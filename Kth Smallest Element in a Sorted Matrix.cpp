class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int count = 0;
        array<int, 2> elem;
        vector<vector<int>> in_queue(matrix.size(), vector<int>(matrix.size(), 0));
        auto compare = [&](array<int,2> elem1, array<int,2>elem2){ return matrix[elem1[0]][elem1[1]] > matrix[elem2[0]][elem2[1]];};
        priority_queue<array<int,2>, vector<array<int,2>>, decltype(compare)> queue(compare);
        queue.push(array<int,2>({0,0}));                                                                                 while(queue.size() && count != k)
        {
            elem = queue.top();
            queue.pop();
            count++;
            if(elem[0]+1 < matrix.size() && !in_queue[elem[0]+1][elem[1]])
            {
                queue.push(array<int,2>({elem[0]+1,elem[1]}));
                in_queue[elem[0]+1][elem[1]] = 1;
            }
            if(elem[1]+1 < matrix.size() && !in_queue[elem[0]][elem[1]+1])
            {
                queue.push(array<int,2>({elem[0],elem[1]+1}));
                in_queue[elem[0]][elem[1]+1] = 1;
            }   
        }
        return matrix[elem[0]][elem[1]];
    }
};
