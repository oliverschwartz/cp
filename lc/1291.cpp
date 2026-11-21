class Solution {
    vector<int> _ret; 

public:
    vector<int> sequentialDigits(int low, int high) {
        add_next(low, high);
        return _ret;
    }

    pair<int,int> msd_and_digits(int x)
    {
        int divs = 0; 
        while (x >= 10)
        {
            x = x / 10;
            ++divs;
        }
        return {x, divs + 1};
    }

    void add_next(int low, int high)
    {
        if (low > high)
        {
            return;
        }

        const auto [msd, digits] = msd_and_digits(low);
        if (msd + digits - 1 > 9)
        {
            if (digits >= 10)
            {
                return;
            }
            int next = std::pow(10, digits); 
            add_next(next, high);
        }
        else
        {
            int val = msd;
            for (int i = 1; i < digits; ++i)
            {
                val = val * 10; 
                val += (msd + i);
            }

            if (low <= val && val <= high)
            {
                _ret.push_back(val);
            }

            int next = (msd + 1) * std::pow(10, digits - 1);
            add_next(next, high);
        }
    }
};
