/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        if(root==NULL){
            return 0;
        }

        vector<long long>levelSum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                sum+=(long long)node->val;

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }  
            }
            levelSum.push_back(sum);
        }

        if(k>levelSum.size()){
            return -1;
        }

        sort(levelSum.begin(),levelSum.end());

        return levelSum[levelSum.size()-k];
    }
};
