class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n + 1, 0); 
        vector<int> outdeg(n + 1, 0); 
        for (const auto& p : trust)
        {
            ++indeg[p[1]];
            ++outdeg[p[0]];
        }

        vector<int> sat;
        for (int i = 1; i <= n; ++i)
        {
            if (indeg[i] == n - 1 && outdeg[i] == 0)
            {
                sat.push_back(i);
            }
        }

        return sat.size() == 1 ? sat.front() : -1;
    }
};
