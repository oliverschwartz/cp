class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> m; 
        char odd_char = '\0';
        for (char c : s)
        {
            ++m[c];
        }

        const int n = s.size();
        string ret(n, '.'); 
        int widx = 0;

        for (const auto& [ch, cnt] : m)
        {
            for (int i = 0; i < cnt / 2; ++i)
            {
                ret[widx] = ch; 
                ret[n - widx - 1] = ch;
                ++widx;
            }
            if (cnt % 2 == 1)
            {
                ret[n / 2] = ch;
            }
        }

        return ret;
    }
};
