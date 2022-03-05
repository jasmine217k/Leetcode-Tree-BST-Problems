class Solution {
public:
    int ans=INT_MAX;
    TreeNode *prev=NULL;
    void inorder(TreeNode *root)
    {
        if(root==NULL)
            return ;

        inorder(root->left);

        if(prev)
        ans=min(ans,abs(root->val-prev->val));
          prev=root;
        inorder(root->right);


    }
    int getMinimumDifference(TreeNode* root) {


    inorder(root);
        return ans;


    }
};
