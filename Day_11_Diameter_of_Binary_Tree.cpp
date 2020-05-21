/* Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them. */


/* Approach - dfs traversal */

// Time Complexity - O(n), where n is number of nodes in tree
// Space Complexity - O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int lengthOfLongestPath = 0;
        dfs(root, lengthOfLongestPath);
        return lengthOfLongestPath ? lengthOfLongestPath - 1 : lengthOfLongestPath;
    }
    int dfs(TreeNode* root, int &lengthOfLongestPath) {
        if (!root) {
            return 0;
        }
        int leftLongestPath = dfs(root->left, lengthOfLongestPath);
        int rightLogestPath = dfs(root->right, lengthOfLongestPath);
        lengthOfLongestPath = max(lengthOfLongestPath, leftLongestPath + rightLogestPath + 1);
        return max(leftLongestPath, rightLogestPath) + 1;
    }
};