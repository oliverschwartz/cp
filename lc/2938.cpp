class Solution {
public:
    long long minimumSteps(string s) {
        long long inv = 0;
        int ones = 0;
        for (char ch : s)
        {
            if (ch == '1') ++ones;
            else inv += ones;
        }
        return inv;
    }
};
