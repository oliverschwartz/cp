class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        const int w1l = word1.length();
        vector<int> suff_match(w1l, 0);

        int cnt = 0; 
        for (int i = w1l - 1; i >= 0; --i)
        {
            if (cnt < word2.size() && word1[i] == word2[word2.size() - cnt - 1])
            {
                ++cnt;
            }
            suff_match[i] = cnt;
        }

        vector<int> soln; 
        int i = 0; 
        int j = 0; 
        bool spent = false;
        while (i < word1.size() && j < word2.size())
        {
            if (word1[i] == word2[j])
            {
                soln.push_back(i);
                ++i; 
                ++j;
            }
            else if (spent)
            {
                ++i;
            }
            else
            {
                // spend credit if we can
                const int rem_chars = word2.size() - j - 1;
                if (rem_chars == 0 || (i + 1 < word1.size() && suff_match[i + 1] >= rem_chars))
                {
                    soln.push_back(i);
                    spent = true;
                    ++i;
                    ++j;
                }
                else
                {
                    ++i;
                }
            }
        }

        return soln.size() == word2.size() ? soln : vector<int>{};
    }
};
