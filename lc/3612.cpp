class Solution {
public:
    string processStr(string s) {
        string ret; 
        ret.reserve(s.size() * 4);

        for (const char ch : s)
        {
            switch (ch)
            {
                case '#':
                {
                    ret += ret; 
                    break;
                }
                case '*':
                {
                    if (ret.size())
                    {
                        ret.pop_back();
                    }
                    break;
                }
                case '%':
                {
                    std::reverse(ret.begin(), ret.end());
                    break;
                }
                default:
                {
                    ret.push_back(ch);
                    break;
                }
            }
        }
        return ret;
    }
};
