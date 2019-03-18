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
    int max_row;
    vector<int> ans;
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
            return ans;

        max_row = 0;
        ans.push_back(root->val);
        BFS(root, 0);
        return ans;
    }
    void BFS(TreeNode* node, int row){
        if(node == NULL) return;

        if(row > max_row){
            ans.push_back(node->val);
            max_row = row;
        } else if(node->val > ans[row]){
            ans[row] = node->val;
        }

        BFS(node->left, row+1);
        BFS(node->right, row+1);
    }
};
