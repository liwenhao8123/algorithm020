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