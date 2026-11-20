class Solution {
    vector<vector<int>> _memo;

public:
    
    int lcp(int i, int j, const vector<int>& nums1, const vector<int>& nums2)
    {
        if (i == nums1.size() || j == nums2.size())
        {
            return 0;
        }
        else if (_memo[i][j] != -1)
        {
            return _memo[i][j];
        }
        else if (nums1[i] != nums2[j])
        {
            return 0;
        }
        _memo[i][j] = 1 + lcp(i + 1, j + 1, nums1, nums2);
        return _memo[i][j];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        _memo.resize(nums1.size(), vector<int>(nums2.size(), -1));
        int best = 0;
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                best = std::max(best, lcp(i, j, nums1, nums2));
            }
        }
        return best;
    }
};
