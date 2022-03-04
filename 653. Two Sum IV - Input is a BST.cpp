class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>s;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(s.find(k-temp->val)==s.end())
                s.insert(temp->val);
            else
                return true;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return false;
    }
};
