class Solution {
public:

    constexpr long long pow10(int exp)
    {
        long long val = 1; 
        for (int i = 0; i < exp; ++i)
        {
            val *= 10;
        }
        return val;
    }

    long long countCommas(long long n) {
        long long prev = 1;
        long long commas = 0;

        for (int exp = 3; exp <= 18; exp += 3)
        {
            // count all commas in the numbers [prev, upper)
            long long upper = pow10(exp);
            long long per_num = (exp / 3) - 1;

            if (n >= upper)
            {
                commas += (upper - prev) * per_num;
            }
            else // n < upper
            {
                commas += (n - prev + 1) * per_num;
                break;
            }

            prev = upper; 
        }

        return commas; 
    }
};
