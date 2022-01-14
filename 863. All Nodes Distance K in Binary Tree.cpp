/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makepar(TreeNode *root,unordered_map<TreeNode *,TreeNode *>&par)
    {
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left)
            {
                par[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                par[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode *,TreeNode *>par;
        makepar(root,par);
        vector<int>vis(502,0);
        queue<TreeNode *>q;
        q.push(target);
        int dis=0;
        vis[target->val]=1;
        while(!q.empty())
        {
            int s=q.size();
            if(dis++==k)
                break;

            for(int i=0;i<s;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left&&vis[temp->left->val]==0)
                {
                    q.push(temp->left);
                    vis[temp->left->val]=1;
                }
                if(temp->right&&vis[temp->right->val]==0)
                {
                    q.push(temp->right);
                    vis[temp->right->val]=1;
                }
                if(par[temp]&&vis[par[temp]->val]==0)
                {
                    q.push(par[temp]);
                    vis[par[temp]->val]=1;
                }
            }
        }
        vector<int>res;
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
