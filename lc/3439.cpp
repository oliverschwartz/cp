class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int prev_end = 0; 
        vector<int> gaps; 
        gaps.reserve(startTime.size());

        for (int i = 0; i < startTime.size(); ++i)
        {
            int gap = startTime[i] - prev_end; 
            gaps.push_back(gap);
            prev_end = endTime[i];
        }

        if (eventTime - prev_end > 0)
        {
            gaps.push_back(eventTime - prev_end);
        }
        
        const int num_gaps = gaps.size();
        if (num_gaps == 0)
        {
            return 0;
        }

        int window = 0;
        for (int i = 0; i < std::min(k + 1, num_gaps); ++i)
        {
            window += gaps[i];
        }

        int best = window; 
        for (int left = 1; left <= num_gaps - (k + 1); ++left)
        {
            window = window - gaps[left - 1] + gaps[left + k];
            best = std::max(best, window);
        }

        return best;
    }
};
