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
    unordered_map<int, int> mp;
    int idx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        idx = 0;

        return func(preorder, 0, inorder.size() - 1);
    }

    TreeNode* func(vector<int>& preorder, int low, int high) {

        // Base case
        if (low > high) {
            return NULL;
        }

        // Create root node
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        // Find root position in inorder
        int id = mp[node->val];

        // Construct left subtree
        node->left = func(preorder, low, id - 1);

        // Construct right subtree
        node->right = func(preorder, id + 1, high);

        return node;
    }
};