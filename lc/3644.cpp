class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = 0xffffffff;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != nums[i])
            {
                k = k & nums[i]; 
            }
        }

        if (k == 0xffffffff)
        {
            return 0;
        }
        return k; 
    }
};
