class Solution {
public:
    void view(TreeNode *root,vector<int>&v,int lev)
    {
        if(root==NULL)
            return;
        if(v.size()==lev)
            v.push_back(root->val);
        view(root->right,v,lev+1);
        view(root->left,v,lev+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        view(root,v,0);
        return v;

    }
};
