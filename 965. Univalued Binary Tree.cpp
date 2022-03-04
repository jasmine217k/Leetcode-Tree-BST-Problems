class Solution {
public:
    bool check(TreeNode *root,int x)
    {
        if(root==NULL)
            return true;
        if(root->val!=x)
            return false;
        return check(root->left,x)&check(root->right,x);
    }
    bool isUnivalTree(TreeNode* root) {
        int x=root->val;
        return check(root,x);
    }
};
