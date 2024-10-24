/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, vector<int>& path) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        path[root->val] = -1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                    path[node->left->val] = node->val;
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    path[node->right->val] = node->val;
                }
            }
        }
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Path(100);
        vector<int> root2Path(100);

        traverse(root1, root1Path);
        traverse(root2, root2Path);

        return root1Path == root2Path;
    }
};
