class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
            return new TreeNode(val);
        TreeNode *curr=root;
        while(true)
        {
            if(root->val<=val)
            {
                if(root->right==NULL)
                {
                    root->right=new TreeNode(val);
                    break;
                }
                else
                    root=root->right;
            }
           else
            {
                if(root->left==NULL)
                {
                    root->left=new TreeNode(val);
                    break;
                }
                else
                    root=root->left;
            }
        }
        return curr;
    }
};
