class Solution {
public:
    TreeNode *form(vector<int>pre,int &idx,int s,int maxx)
    {
        if(idx>=s||pre[idx]>maxx)
            return NULL;
        TreeNode *root=new TreeNode(pre[idx++]);
        root->left=form(pre,idx,s,root->val);
        root->right=form(pre,idx,s,maxx);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int s=preorder.size();
        int idx=0;
       return form(preorder,idx,s,INT_MAX);
    }
};
