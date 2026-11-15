class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>{});
        vector<unordered_set<int>> anc(n, unordered_set<int>{});
        vector<int> indegs(n, 0);
        
        for (const auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            ++indegs[e[1]];
        }

        deque<int> q; 
        for (int i = 0; i < n; ++i)
        {
            if (indegs[i] == 0)
            {
                q.push_back(i);
            }
        }

        // Run Kahn's algorithm.
        while (!q.empty())
        {
            const auto sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                const int removed = q.front();
                q.pop_front();

                for (const auto nbor : adj[removed])
                {
                    anc[nbor].insert(removed);
                    for (const auto parent_anc : anc[removed])
                    {
                        anc[nbor].insert(parent_anc);
                    }

                    if (--indegs[nbor] == 0)
                    {
                        q.push_back(nbor);
                    }
                }
            }
        }


        vector<vector<int>> ret; 
        for (int i = 0; i < n; ++i)
        {
            vector<int> tmp; 
            for (auto val : anc[i])
            {
                tmp.push_back(val);
            }
            std::sort(tmp.begin(), tmp.end());
            ret.push_back(std::move(tmp));
        }

        return ret; 
    }
};
