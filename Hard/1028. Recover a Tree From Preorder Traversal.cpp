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
    TreeNode* solve(string &traversal, int &i, int depth){

        int n=traversal.size();

        if(i>=traversal.size()){
            return NULL;
        }

        int j=i;
        while(j<n && traversal[j]=='-'){
            j++;
        }

        int dashCount=j-i;

        if(dashCount != depth){
            return NULL;
        }

        int num=0;
        i=j;
        while(i<n && isdigit(traversal[i])){
            num =(num*10)+(traversal[i]-'0');
            i++;
        }

        TreeNode* node =new TreeNode(num);

        node->left=solve(traversal,i,depth+1);
        node->right=solve(traversal,i,depth+1);

        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.size();
        int i=0;
        int depth=0;

        return solve(traversal,i,depth);
    }
};
