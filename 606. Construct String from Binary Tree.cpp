class Solution {
public:
    string pre(TreeNode *root)
    {
        if(root==NULL)
            return "";
       string s;
        s+=to_string(root->val);
       if(root->left)
           s+='('+ pre(root->left)+ ')';   // a combination of root-left-right should always be enclosed within brackets
        else if(root->right)
            s+='()';              // if a node has only right child ,we have to add()
        if(root->right)
            s+='('+pre(root->right)+')';

        return s;
    }
    string tree2str(TreeNode* root) {
       return pre(root);
    }
};
