/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* createTree(vector<int>& sortedarray, int p, int q)
    {
        int mid = (p+q)/2;
        if(mid>q || mid<p) return nullptr;
        
        TreeNode *root = new TreeNode(sortedarray[mid]);
        if(mid == p) root->left = nullptr;
        else root->left = createTree(sortedarray, p, mid-1);
        if(mid == q) root->right = nullptr;
        else root->right = createTree(sortedarray, mid+1, q);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> sortedarray;
        while(head != nullptr)
        {
            sortedarray.push_back(head->val);
            head = head->next;
        }
        TreeNode *root = createTree(sortedarray, 0, sortedarray.size()-1);
        
        return root;
    }
};
