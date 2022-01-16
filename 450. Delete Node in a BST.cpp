class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(root->val==key)
            return helper(root);
        TreeNode *dummy=root;
        while(root)
        {
            if(root->val>key)
            {
                if(root->left&&root->left->val==key)
                {
                    root->left=helper(root->left);
                    break;
                }
                else
                    root=root->left;
            }
            else
            {
                if(root->right&&root->right->val==key)
                {
                    root->right=helper(root->right);
                    break;
                }
                else
                    root=root->right;
            }
        }
        return dummy;
    }

    TreeNode *helper(TreeNode *root)
    {
        if(root->left==NULL)
            return root->right;
        if(root->right==NULL)
            return root->left;

        TreeNode *rc=root->left;
        TreeNode *rightmost=last(root->right);
        rightmost->left=rc;
        return root->right;
    }
    TreeNode *last(TreeNode *root)
    {
        while(root->left)
            root=root->left;
        return root;
    }
};
