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
    int deepest_leaves = 0;
    
    int find_depth(TreeNode* node, int depth = 1)
    {
        if(node->left == nullptr && node-> right == nullptr)
            return depth;
        else if(node->left == nullptr)
            return find_depth(node->right, depth+1);
        else if(node->right == nullptr)
            return find_depth(node->left, depth+1);
        else
            return max(find_depth(node->left, depth+1), find_depth(node->right, depth+1));
    }
    
    void traverse(TreeNode* node, const int depth, int current_depth = 1)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            if(current_depth == depth)
                deepest_leaves += node->val;
        }
        else if(node->left == nullptr)
            traverse(node->right, depth, current_depth+1);
        else if(node->right == nullptr)
            traverse(node->left, depth, current_depth+1);
        else
        {
            traverse(node->left, depth, current_depth+1);
            traverse(node->right, depth, current_depth+1);
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int depth = find_depth(root);
        traverse(root, depth);
        return deepest_leaves;
    }
};
