class Solution {
    unordered_map<int, vector<int>> _adj;
    unordered_set<int> _visited;

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
        {
            return -1; 
        }

        for (const auto& e : connections)
        {
            _adj[e[0]].push_back(e[1]);
            _adj[e[1]].push_back(e[0]);
        }

        int cmp_cnt = 0; 
        for (int i = 0; i < n; ++i)
        {
            if (!_visited.contains(i))
            {
                ++cmp_cnt;
                dfs(i);
            }
        }

        return cmp_cnt - 1;
    }

    void dfs(int node)
    {
        _visited.insert(node);
        if (_adj.find(node) == _adj.end())
        {
            return;
        }
        
        for (int nbor : _adj[node])
        {
            if (!_visited.contains(nbor))
            {
                dfs(nbor);
            }
        }
    }
};
