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
    void addNodeAtDepth(TreeNode *node, int current_depth, int &v, int &d)
    {
        if(current_depth != d-1)
        {
            if(node->left != nullptr)
                addNodeAtDepth(node->left, current_depth+1, v, d);
            if(node->right != nullptr)
                addNodeAtDepth(node->right, current_depth+1, v, d);
        }
        else
        {
            TreeNode *LeftChild = new TreeNode(v, node->left, nullptr);
            TreeNode *RightChild = new TreeNode(v, nullptr, node->right);
            node->left = LeftChild;
            node->right = RightChild;
        } 
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            cout<<"Entered";
            TreeNode *LeftChild = new TreeNode(v, root, nullptr);
            return LeftChild;
        }
        else
            addNodeAtDepth(root, 1, v, d);
        return root;
    }
};
