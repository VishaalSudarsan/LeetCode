/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int findDepth(TreeNode* root, int depth = 0)
    {
        if(root ==  nullptr)
            return depth-1;
        else
            return max(findDepth(root->right, depth+1), findDepth(root->left, depth+1));
    }
    
    void buildLevelOrder(TreeNode* root, vector<vector<int>>& levelorder, int depth = 0)
    {
        if(root ==  nullptr)
            return;
        levelorder[depth].push_back(root->val);
        buildLevelOrder(root->left, levelorder, depth+1);
        buildLevelOrder(root->right, levelorder, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelorder;
        int depth = findDepth(root);
        for(int i=0;i<depth+1;i++)
        {
            vector<int> temp;
            levelorder.push_back(temp);
        }
        
        buildLevelOrder(root, levelorder);
        return levelorder;
    }
};
