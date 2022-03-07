class Solution {
public:
    int ans=INT_MIN;
    int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int l=height(root->left);
        int r=height(root->right);
        ans=max(ans,1+l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       height(root);
        return ans-1;

    }
};
