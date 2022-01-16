class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        map<int,int>m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;

        TreeNode *root= build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,m);
        return root;
    }
    TreeNode *build(vector<int>&in,vector<int>&post,int a,int b,int c,int d,map<int,int>&m)
    {
        if(a>b||c>d)
            return NULL;
        TreeNode *root=new TreeNode(post[d]);
        int f=m[post[d]];

        TreeNode *c1=build(in,post,a,f-1,c,c+f-a-1,m);
        TreeNode *c2=build(in,post,f+1,b,c+f-a,d-1,m);
        root->left=c1;
        root->right=c2;
        return root;
    }
};
