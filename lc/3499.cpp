class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prev_run = -1; 
        int run = 0; 
        int ones = 0;
        int gain = 0; 

        for (const char ch : s)
        {
            if (ch == '0')
            {
                ++run;
            }
            else
            {
                ++ones; 
                if (run > 0)
                {
                    if (prev_run > 0)
                    {
                        gain = std::max(gain, prev_run + run);
                    }
                    prev_run = run;
                    run = 0;
                }
            }
        }
                
        if (run > 0 && prev_run > 0)
        {
            gain = std::max(gain, prev_run + run);
        }

        return ones + gain;
    }
};
