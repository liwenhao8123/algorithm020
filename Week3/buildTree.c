/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    //终止条件
    if (preorder == NULL || inorder == NULL)
        return NULL;
    if (preorderSize <= 0 || inorderSize <= 0)
        return NULL;

    //本层逻辑
    int leftNum = 0;
    int rightNum = 0;
    struct TreeNode * tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    //头序遍历第一个就是根节点，先取出根节点
    tmp->val = preorder[0];
    //在中序遍历中找到根节点
    for (int i = 0; i < inorderSize; i++){
        if (inorder[i] == tmp->val){
            break;  //找到了根节点的索引
        }
        leftNum++;
    }
    rightNum = inorderSize - leftNum - 1;
    //调用下一层
    //构建本层根节点的左子树   前序从根节点（第一个）后面开始   中序从第一个开始
    tmp->left =  buildTree(preorder + 1, leftNum, inorder, leftNum);
    //构建本层节点的右子树
    tmp->right = buildTree(preorder+1+leftNum, rightNum, inorder+leftNum+1, rightNum);
    //回收处理
    return tmp;
}