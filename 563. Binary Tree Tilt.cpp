class Solution {
public:
    int solve(TreeNode *root,int &sum)
    {
        if(root==NULL)
            return 0;
        int l=0,r=0;
        l+=solve(root->left,sum);
        r+=solve(root->right,sum);
        sum+=abs(l-r);
        return root->val+l+r;
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return sum;
    }
};
