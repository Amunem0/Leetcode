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
    void depth(TreeNode* root,int d,int &maxD,unordered_map<int,int>&mp){
        if(root==NULL){
            return;
        }
        maxD=max(maxD,d);
        mp[root->val]=d;

        depth(root->left,d+1,maxD,mp);
        depth(root->right,d+1,maxD,mp);
        
    }

    TreeNode* LCA(TreeNode* root,int maxD,unordered_map<int,int>&mp){
        if(root==NULL || mp[root->val]==maxD){
            return root;
        }

        TreeNode* l=LCA(root->left,maxD,mp);
        TreeNode* r=LCA(root->right,maxD,mp);

        if(l!=NULL && r!=NULL){
            return root;
        }

        if(l!=NULL){
            return l;
        }
        return r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int,int>mp;
        int maxD=0;
        depth(root,0,maxD,mp);

        return LCA(root,maxD,mp);
    }
};
