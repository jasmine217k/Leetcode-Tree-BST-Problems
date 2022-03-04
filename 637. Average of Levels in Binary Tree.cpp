//using bfs
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<double>v;
        while(!q.empty())
        {
            int s=q.size();
            double sum=0;
            for(int i=0;i<s;i++)
            {
           TreeNode *temp=q.front();
            q.pop();
                sum+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            sum=sum/s;
            v.push_back(sum);
        }
        return v;

    }
};

//using dfs
class Solution {
public:
    void solve(TreeNode *root,map<int,vector<int>>&m,int d)
    {
      if(root==NULL)
          return;
        m[d].push_back(root->val);
        solve(root->left,m,d+1);
        solve(root->right,m,d+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
    map<int,vector<int>>m;
        solve(root,m,0);
        vector<double>v;
        for(auto x:m)
        {
            int s=x.second.size();
            double sum=0;
            for(auto i:x.second)
                sum+=i;
            v.push_back(sum/s);

        }
        return v;

    }
};
