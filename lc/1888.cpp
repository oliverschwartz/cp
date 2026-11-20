class Solution {
public:
    int minFlips(string s) {
        const int n = s.size();
        const bool neven = n % 2 == 0;
        s += s; 

        int evens = 0; 
        int odds = 0; 
        for (int i = 0; i < n; ++i)
        {
            evens += (i % 2 == 0) ? static_cast<int>(s[i] == '1') : 0;
            odds += (i % 2 == 1) ? static_cast<int>(s[i] == '1') : 0;
        }

        int min_flips = INT_MAX;

        for (int left = 0; left <= n; ++left)
        {
            if (neven)
            {
                int a = std::abs(evens - n / 2) + odds;
                int b = std::abs(odds - n / 2) + evens;
                min_flips = std::min(min_flips, std::min(a, b));
            }
            else
            {
                int a = std::abs(evens - (n + 1) / 2) + odds;
                int b = std::abs(odds - n / 2) + evens;
                min_flips = std::min(min_flips, std::min(a, b));
            }

            if (left < n)
            {
                const int old_even = evens;
                const bool old_is_one = s[left] == '1';
                const bool new_is_one = s[left + n] == '1';

                evens = odds + (!neven ? new_is_one : 0);
                odds = old_even - (old_is_one ? 1 : 0) + 
                    ((neven && new_is_one) ? 1 : 0);
            }
        }

        return min_flips;
    }
};
