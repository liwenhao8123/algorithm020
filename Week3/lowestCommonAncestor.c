/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    //终止条件
    if (root == NULL || root == p || root == q)
        return root;
    //调用下一层
    struct TreeNode * left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode * right = lowestCommonAncestor(root->right, p, q);
    //本层逻辑
    //如果两个都找到了则返回本层，就是公共祖先
    if (left != NULL && right != NULL)
        return root;
    //到这说明只知道一个left或right，那么返回找到的那个
    return left != NULL ? left:right;
}