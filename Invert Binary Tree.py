# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is not None:
            root.left, root.right = root.right, root.left
            if root.left is not None and root.right is not None:
                self.invertTree(root.left)
                self.invertTree(root.right)
            elif root.left is not None:
                self.invertTree(root.left)
            elif root.right is not None:
                self.invertTree(root.right)
        return root
        
