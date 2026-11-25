class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        
        static constexpr std::array<std::array<int,2>,4> ds = {{{0,1}, {1,0}, {0,-1}, {-1,0}}};
        vector<pair<int,int>> stack; 

        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++cnt; 
                    grid[i][j] = '0';
                    stack.push_back(make_pair(i, j));

                    while (stack.size())
                    {
                        pair<int,int> p = stack.back();
                        stack.pop_back();

                        for (const auto& d : ds)
                        {
                            int x = p.first + d[0];
                            int y = p.second + d[1];
                            if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] == '1')
                            {
                                grid[x][y] = '0';
                                stack.push_back(make_pair(x, y));
                            }
                        }
                    }
                }
            }
        }
        return cnt; 
    }
};
