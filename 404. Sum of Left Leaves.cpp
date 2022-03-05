class Solution {
public:
    void findsum(TreeNode *root,int &sum,int c)
    {
        if(root==NULL)
            return;
        if(c==1&&root->left==NULL&&root->right==NULL)
           sum+=root->val;
         findsum(root->left,sum,1);
        findsum(root->right,sum,0);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0,c=-1;
        findsum(root,sum,c);
        return sum;

    }
};
