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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }

        queue<TreeNode*>q;
        vector<int>Sum;

        q.push(root);

        //FIND SUM OF EACH LEVEL AND STORE IN Sums
        while(!q.empty()){
            int currLvlSum=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                currLvlSum+=node->val;
            }
            Sum.push_back(currLvlSum);
        }


        //UPDATE EACH NOTE VALUE WITH COUSIN SUM
        q.push(root);
        root->val=0;
        int level=1;
         while(!q.empty()){
            int currLvlSum=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                int siblingSum=0;
                siblingSum+=node->left!=NULL?node->left->val:0;
                siblingSum+=node->right!=NULL?node->right->val:0;

                if(node->left){
                    node->left->val=Sum[level]-siblingSum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val=Sum[level]-siblingSum;
                    q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};
