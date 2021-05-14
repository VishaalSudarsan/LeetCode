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
    stack<TreeNode*> rightchilds;
    void flattenTree(TreeNode* root)
    {
        if(root == nullptr || (root->right == nullptr && root->left == nullptr))
            return;
        if(root->left == nullptr)
            flattenTree(root->right);
        if(root->right != nullptr)
        {
            TreeNode *temp = root->right;
            rightchilds.push(temp);
        }
        root->right = root->left;
        root->left  = nullptr;
        flattenTree(root->right);
    }
    void flatten(TreeNode* root) {
        if(root ==  nullptr)
            return;
        flattenTree(root);
        TreeNode *leaf = root;
        while(leaf->right != nullptr)
            leaf = leaf->right;
        while(!rightchilds.empty())
        {
            leaf->right = rightchilds.top();
            rightchilds.pop();
            flattenTree(leaf->right);
            while(leaf->right != nullptr)
                leaf = leaf->right;
        }
    }
};
