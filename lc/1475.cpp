class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size(); 
        vector<int> ans(n, -1); 
        vector<int> right;

        for (int i = n - 1; i >= 0; --i)
        {
            if (right.empty())
            {
                ans[i] = prices[i];
            }
            else
            {
                for (auto it = right.rbegin(); it != right.rend(); ++it)
                {
                    if (*it <= prices[i])
                    {
                        ans[i] = prices[i] - *it;
                        break;
                    }
                }
                if (ans[i] == -1)
                {
                    ans[i] = prices[i];
                }
            }

            while (right.size() && right.back() > prices[i])
            {
                right.pop_back();
            }
            right.push_back(prices[i]);
        }
        return ans;
    }
};
