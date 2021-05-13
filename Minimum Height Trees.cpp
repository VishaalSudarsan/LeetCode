class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (!edges.size()) return vector<int>(1, 0);
        unordered_map<int, set<int>> adjecencylist;
        vector<int> connections(n, 0);
        int remainingnodes=n;
        
        for (vector<int> pair : edges)
        {
            adjecencylist[pair[0]].insert(pair[1]);
            adjecencylist[pair[1]].insert(pair[0]);
            connections[pair[0]]++;
            connections[pair[1]]++;
        }

        set<int> leaves;
        vector<bool> removednodes;
        for (int i = 0; i < n; i++)
            if (connections[i] == 1)
            {
                leaves.insert(i);
                connections[i] = 0;
                removednodes.push_back(true);
                remainingnodes--;
            }
            else
                removednodes.push_back(false);


        while (remainingnodes != 0)
        {
            for (int leaf : leaves)
                for (int neighbour : adjecencylist[leaf])
                    if(!removednodes[neighbour])
                        connections[neighbour] = max(1, connections[neighbour] - 1);

            leaves.clear();
            for (int i = 0; i < n; i++)
                if (connections[i] == 1)
                {
                    leaves.insert(i);
                    connections[i] = 0;
                    removednodes[i] = true;
                    remainingnodes--;
                }
        }

        return vector<int>(leaves.begin(), leaves.end());
    }
};
