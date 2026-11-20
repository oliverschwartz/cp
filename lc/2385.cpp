class Solution {
    unordered_map<TreeNode*, vector<TreeNode*>> adj; 
    TreeNode* _start = nullptr;

public:
    int amountOfTime(TreeNode* root, int start) 
    {
        dfs(root, start);
        deque<TreeNode*> dq; 
        unordered_set<TreeNode*> visited; 
        dq.push_back(_start);
        visited.insert(_start);
        int iters = 0;
        while (dq.size())
        {
            const int n = dq.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode* n = dq.front();
                dq.pop_front();
                for (auto* p : adj[n])
                {
                    if (!visited.contains(p))
                    {
                        visited.insert(p);
                        dq.push_back(p);
                    }
                }
            }

            if (dq.size())
            {
                ++iters;
            }
        }
        return iters;
    }

    void dfs(TreeNode* n, int start)
    {
        if (n->val == start)
        {
            _start = n;
        }
        if (n->left)
        {
            adj[n].push_back(n->left);
            adj[n->left].push_back(n);
            dfs(n->left, start);
        }
        if (n->right)
        {
            adj[n].push_back(n->right);
            adj[n->right].push_back(n);
            dfs(n->right, start);
        }
    }
};
