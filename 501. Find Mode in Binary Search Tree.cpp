BRUTE FORCE APPROACH


void cnt(TreeNode *root,unordered_map<int,int>&m,int &maxx)
    {
        if(root==NULL)
            return;
        m[root->val]++;
        maxx=max(maxx,m[root->val]);
        cnt(root->left,m,maxx);
        cnt(root->right,m,maxx);
    }

    vector<int> findMode(TreeNode* root) {
       unordered_map<int,int>m;
        int maxx=-1;
        cnt(root,m,maxx);
        vector<int>v;
        for(auto it:m)
        {
            if(it.second==maxx)
                v.push_back(it.first);
        }
        return v;
    }

 ******************************************************************************************************************************************************************************
    OPTIMISED APPROACH

    class Solution {
public:
    int curr=0;
    int maxx=-1,prev;
   void inorder(TreeNode *root,vector<int>&v)
   {
       if(root==NULL)
           return;
       inorder(root->left,v);
       if(root->val==prev)
       {
          curr++;
       }
       else
           curr=1;
       if(curr==maxx)
       {
           v.push_back(root->val);
       }
       else if(curr>maxx)
       {
         maxx=max(curr,maxx);
           v.clear();
           v.push_back(root->val);
       }
       prev=root->val;
       inorder(root->right,v);
   }

    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        prev=root->val;
       inorder(root,v);
        return v;
    }
};
