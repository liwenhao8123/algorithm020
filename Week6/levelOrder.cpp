/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//二叉树的层序遍历，即逐层地，从左往右访问所有节点 
//BFS 广度优先搜索，利用queue队列

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) 
            return ret;

        queue<TreeNode*> queueNode;
        queueNode.push(root);

        while (!queueNode.empty()){
            int currentLevelSize = queueNode.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = queueNode.front();
                queueNode.pop();
                ret.back().push_back(node->val);
                if (node->left)
                    queueNode.push(node->left);
                if (node->right)
                    queueNode.push(node->right);
            }
        }

        return ret;
    }
};