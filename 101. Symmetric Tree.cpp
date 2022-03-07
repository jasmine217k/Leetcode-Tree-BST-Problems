class Solution {
public:
    bool check(TreeNode *root1,TreeNode *root2)
    {
        if(root1==NULL&&root2==NULL)
            return true;
        if(root1==NULL||root2==NULL)
            return false;
        if(root1->val!=root2->val)
            return false;
        return check(root1->left,root2->right)&check(root1->right,root2->left);

    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};
