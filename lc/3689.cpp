class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minval = INT_MAX; 
        int maxval = INT_MIN;
        for (auto n : nums)
        {
            minval = std::min(minval, n);
            maxval = std::max(maxval, n);
        }
        return static_cast<long long>(maxval - minval) * k;
    }
};
