class Solution {
public:

    void form(TreeNode *root,string &s)
    {

        if(root==NULL)
        {
            return;
        }

        s+='(';
        s+=to_string(root->val);

         if(root->left==NULL&&root->right)
                s+="()";
        form(root->left,s);
        form(root->right,s);

            s+=")";
    }
    string tree2str(TreeNode* root) {
        string s="";
        form(root,s);
        return s.substr(1,s.length()-2);
    }
};
