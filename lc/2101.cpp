class Solution {
    unordered_map<int,int> _memo;
    vector<vector<int>> _adj;
    unordered_set<int> _visited; 

public:
    
    bool explodes(const vector<int>& a, const vector<int>& b)
    {
        const double xdiff = std::pow(b[0] - a[0], 2);
        const double ydiff = std::pow(b[1] - a[1], 2);
        return xdiff + ydiff <= std::pow(a[2], 2);
    }


    int num_reachable(int node)
    {
        _visited.insert(node);
        int cnt = 1;
        for (auto nbor : _adj[node])
        {
            if (!_visited.contains(nbor))
            {
                cnt += num_reachable(nbor);
            }
        }
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        const int n = bombs.size();
        _adj.resize(n);

        for (int i = 0; i < bombs.size(); ++i)
        {
            for (int j = i + 1; j < bombs.size(); ++j)
            {
                if (explodes(bombs[i], bombs[j]))
                {
                    _adj[i].push_back(j);
                }
                if (explodes(bombs[j], bombs[i]))
                {
                    _adj[j].push_back(i);
                }
            }
        }

        int best = 1;
        for (int i = 0; i < n; ++i)
        {
            best = std::max(best, num_reachable(i));
            _visited.clear();
        }

        return best;
    }
};
