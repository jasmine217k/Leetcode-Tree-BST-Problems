class Solution {
public:
    bool correct(TreeNode *root,long int s,long int e)
    {
        if(root==NULL)
            return true;
        if(root->val<=s||root->val>=e)
            return false;
        return correct(root->left,s,root->val)&&correct(root->right,root->val,e);
    }
    bool isValidBST(TreeNode* root) {
        return correct(root,LONG_MIN,LONG_MAX);
    }
};
