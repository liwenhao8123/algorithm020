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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) 
            return ret;

        bool isOrderLeft = true;
        queue<TreeNode*> queueNode;
        queueNode.push(root);     

        while (!queueNode.empty()){
            deque<int> tmpLevel;
            int currentLevelSize = queueNode.size();
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = queueNode.front();
                queueNode.pop();
                if (isOrderLeft){
                    tmpLevel.push_back(node->val);
                }else{
                    tmpLevel.push_front(node->val);
                }
                if (node->left)
                    queueNode.push(node->left);
                if (node->right)
                    queueNode.push(node->right);
            }
            isOrderLeft = !isOrderLeft;
            ret.push_back(vector<int>{tmpLevel.begin(), tmpLevel.end()});
        }           
        return ret;
    }
};