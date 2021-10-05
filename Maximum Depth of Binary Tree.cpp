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
    int maxdepth = 0;
    void maxDepthInner(TreeNode* node, int depth)
    {
        if(node == nullptr)
            return;
        if(node->right == nullptr && node->left == nullptr)
        {
            if( depth > maxdepth )
                maxdepth = depth;
        }
        if(node->left != nullptr)
            maxDepthInner( node->left, depth+1 );
        if(node->right != nullptr)
            maxDepthInner( node->right, depth+1 );
    }
    int maxDepth(TreeNode* root) 
    {
        maxDepthInner( root, 1 );
        return maxdepth;
    }
};
