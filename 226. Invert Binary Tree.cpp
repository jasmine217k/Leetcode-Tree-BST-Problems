//using bfs
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();

                swap(temp->left,temp->right);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return root;
    }
};


//using dfs

class Solution {
public:
    void solve(TreeNode *&root)
    {
     if(root==NULL)
            return ;
      swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
    solve(root);
        return root;
    }
};
