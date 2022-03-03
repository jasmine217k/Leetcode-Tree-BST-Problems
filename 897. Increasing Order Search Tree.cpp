class Solution {
public:
    void form(TreeNode *root,TreeNode *&res)
    {
        if(root==NULL)
            return;
        form(root->left,res);
        res->right=root;
        res->left=NULL;
        res=root;
        form(root->right,res);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *res=new TreeNode();
        TreeNode *ans=res;
        form(root,res);
        res->right=NULL;
        res->left=NULL;
        return ans->right;

    }
};
