class BSTIterator {
    private:
    vector<int>v;
    int i=0;
public:
    BSTIterator(TreeNode* root) {
        inorder(v,root);
    }
    void inorder(vector<int>&v,TreeNode *root)
    {
        if(root==NULL)
            return;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }

    int next() {
        return v[i++];
    }

    bool hasNext() {
        if(i>=v.size())
            return false;
        return true;
    }
};
