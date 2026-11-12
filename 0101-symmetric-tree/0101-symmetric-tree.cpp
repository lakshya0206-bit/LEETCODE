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

    bool isSame(TreeNode* p, TreeNode* q){

        if(p == NULL && q == NULL)
        return true;

        if(p == NULL || q == NULL)
        return false;

        if(p-> val!= q -> val)
        return false;

        bool p1 = isSame( p -> left , q -> right);
        bool q1 = isSame(p -> right, q -> left);

        if(p1==true && q1==true)
        return true;

    return false;     
    }
    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
        return true;

        return isSame(root -> left, root -> right);
        
    }
};