/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            int minn=q.front().second;
            int start,end;
            for(int i=0;i<s;i++)
            {
                int x=q.front().second-minn;
                TreeNode *temp=q.front().first;
                q.pop();
                if(temp->left)
                {
                    q.push({temp->left,x*2+1});

                }
                if(temp->right)
                {
                    q.push({temp->right,x*2+2});
                }
                if(i==0)
                    start=x;
                if(i==s-1)
                    end=x;
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};
