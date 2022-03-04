class Solution {
public:
    void sequence(vector<int>&v,TreeNode *root)
    {
        if(root==NULL)
            return;
        sequence(v,root->left);
        if(root->left==NULL&&root->right==NULL)
            v.push_back(root->val);
        sequence(v,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        sequence(v1,root1);
        sequence(v2,root2);
        return v1==v2;
    }
};
