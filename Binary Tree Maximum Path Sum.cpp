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
    
    int calculateMaxPathSum(TreeNode* root, int& max_cupPath)
    {
        int leftChild, rightChild, parent;
        if(root->left == nullptr && root->right == nullptr)
            return root->val;
        else if(root->left ==  nullptr)
        {
            rightChild = calculateMaxPathSum(root->right, max_cupPath);
            max_cupPath = max({rightChild, max_cupPath});
            return max({root->val, rightChild + root->val});
        }
        else if(root->right ==  nullptr)
        {
            leftChild = calculateMaxPathSum(root->left, max_cupPath);
            max_cupPath = max({leftChild, max_cupPath});
            return max({root->val, leftChild + root->val});
        }
        else
        {
            leftChild = calculateMaxPathSum(root->left, max_cupPath);
            rightChild = calculateMaxPathSum(root->right, max_cupPath);
            max_cupPath = max({rightChild + leftChild + root->val, rightChild, leftChild, max_cupPath });
            return max({ root->val, rightChild + root->val, leftChild + root->val });
        }        
    }
    
    int maxPathSum(TreeNode* root) {
        int max_cupPath = INT_MIN, max_rootPath;
        max_rootPath =  calculateMaxPathSum(root, max_cupPath);
        return max(max_rootPath, max_cupPath);
    }
};
