class Solution {
public:
    void findpath(TreeNode *root,vector<string>&v,string s)
    {
        if(root==NULL)
         return;
        if(s=="")
        s+=to_string(root->val);
        else
        {s+="->";
         s+=to_string(root->val);
        }
        if(root->left==NULL&&root->right==NULL)
        {
           v.push_back(s);
            return;
        }
        findpath(root->left,v,s);
        findpath(root->right,v,s);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        string s="";
         findpath(root,v,s);
        return v;
    }
};
