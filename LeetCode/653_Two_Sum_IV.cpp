/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <set>
#include <queue>

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> hash;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            TreeNode* ele = q.front();
            q.pop();

            if(!ele)
                continue;

            if(hash.find(k - ele->val) != hash.end()){
                return true;
            }

            hash.insert(ele->val);
            q.push(ele->left);
            q.push(ele->right);
        }

        return false;
    }
};
