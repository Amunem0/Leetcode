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
    int solve(TreeNode* root, int currLevel, vector<int> &level,
              vector<int>& height, vector<int> &levelMaxHeight,
              vector<int> &levelSecondMaxHeight) {
        if (root == NULL) {
            return 0;
        }
        int left = 1 + solve(root->left, currLevel + 1, level, height,
                             levelMaxHeight, levelSecondMaxHeight);
        int right = 1 + solve(root->right, currLevel + 1, level, height,
                              levelMaxHeight, levelSecondMaxHeight);

        level[root->val] = currLevel;
        height[root->val] = max(left, right);

        if (levelMaxHeight[currLevel] < height[root->val]) {
            levelSecondMaxHeight[currLevel] = levelMaxHeight[currLevel];
            levelMaxHeight[currLevel] = height[root->val];
        } else if (levelSecondMaxHeight[currLevel] < height[root->val]) {
            levelSecondMaxHeight[currLevel] = height[root->val];
        }
        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> height(1e5 + 1, 0);
        vector<int> levelMaxHeight(1e5 + 1,0);
        vector<int> levelSecondMaxHeight(1e5 + 1,0);
        vector<int> level(1e5 + 1, 0);
        solve(root, 0, level, height, levelMaxHeight, levelSecondMaxHeight);

        vector<int> ans;
        for (auto& node : queries) {
            int currNodeLevel = level[node];

            if (levelMaxHeight[currNodeLevel] == height[node]) {
                ans.push_back(currNodeLevel+levelSecondMaxHeight[currNodeLevel]-1);
            } else {
                ans.push_back(currNodeLevel+levelMaxHeight[currNodeLevel]-1);
            }
        }
        return ans;
    }
};
