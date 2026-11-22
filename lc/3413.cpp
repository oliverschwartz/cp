class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        // sort intervals from left to right
        std::sort(coins.begin(), coins.end(), [](const auto& l, const auto& r) {
            return l[0] < r[0];
        });
        const int n = coins.size();

        vector<long long> pref(n, 0); 
        pref[0] = static_cast<long long>(coins[0][2]) * (coins[0][1] - coins[0][0] + 1);
        for (int i = 1; i < n; ++i)
        {
            pref[i] = pref[i - 1] + static_cast<long long>(coins[i][2]) * (coins[i][1] - coins[i][0] + 1);
        }

        long long max_coins = 0; 
        int right = 1; // coins[right] should be strictly outside window

        // consider all windows that begin at coins[i][0]
        for (int i = 0; i < n; ++i)
        {
            const int end = coins[i][0] + k - 1;
            while (right < n && !(coins[right][0] > end))
            {
                ++right;
            }

            long long collected = pref[right - 1] - (i == 0 ? 0 : pref[i - 1]);
            if (end < coins[right - 1][1])
            {
                collected -= (coins[right - 1][1] - end) * static_cast<long long>(coins[right - 1][2]);
            }

            max_coins = std::max(collected, max_coins);
        }

        // consider all windows that end at coins[i][0]
        int left = n - 2;
        for (int i = n - 1; i >= 0; --i)
        {
            const int end = coins[i][1] - k + 1;
            while (left >= 0 && !(coins[left][1] < end))
            {
                --left;
            }

            // left is not in the window, so subtract pref[left]
            long long collected = pref[i] - (left < 0 ? 0 : pref[left]);
            if (end > coins[left + 1][0])
            {
                collected -= (end - coins[left + 1][0]) * static_cast<long long>(coins[left + 1][2]);
            }

            max_coins = std::max(collected, max_coins);
        }

        return max_coins;
    }
};
