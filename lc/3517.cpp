class Solution {
public:
    string smallestPalindrome(string s) {
        array<int,26> cnt {}; 
        for (char c : s)
        {
            ++cnt[c - 'a'];
        }

        const int n = s.size();
        string ret(n, '.'); 
        int widx = 0;

        for (int i = 0; i < 26; ++i)
        {
            const char c = static_cast<char>(i + 'a'); 
            if (cnt[i] % 2 == 1)
            {
                ret[n / 2] = c;
                --cnt[i];
            }

            while (cnt[i] > 0)
            {
                ret[widx] = c;
                ret[n - widx - 1] = c;
                ++widx;
                cnt[i] = cnt[i] - 2;
            }
        }

        return ret;
    }
};
