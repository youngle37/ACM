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
    int idx;
    int ans;
    int findBottomLeftValue(TreeNode* root) {
        idx = 1;
        ans = root->val;
        BFS(root, 1);
        return ans;
    }
    void BFS(TreeNode* node, int now){
        if(node == NULL) return;

        if(now > idx){
            idx = now;
            ans = node->val;
        }

        BFS(node->left, now+1);
        BFS(node->right, now+1);
    }
};
