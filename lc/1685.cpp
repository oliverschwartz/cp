class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int n = nums.size();
        vector<int> lr(n, 0);
        vector<int> rl(n, 0);

        for (int i = 1; i < n; ++i)
        {
            lr[i] = lr[i - 1] + (nums[i] - nums[i - 1]) * i;

            const int j = n - 1 - i;
            rl[j] = rl[j + 1] + (nums[j + 1] - nums[j]) * (n - 1 - j); 
        }

        for (int i = 0; i < n; ++i)
        {
            lr[i] += rl[i];
        }
        return lr;
    }
};
