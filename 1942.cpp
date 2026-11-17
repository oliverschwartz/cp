class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> indices(times.size()); 
        std::iota(indices.begin(), indices.end(), 0);
        std::stable_sort(indices.begin(), indices.end(), [&times](int i, int j) {
            return times[i] < times[j];
        });
        std::sort(times.begin(), times.end(), [](const auto& t0, const auto& t1) {
            return t0[0] < t1[0];
        });

        priority_queue<int, vector<int>, std::greater<int>> free; 

        struct ival { int start; int end; int chair; };
        auto cmp = [](const ival& i0, const ival& i1) {
            return i0.end > i1.end; 
        };
        priority_queue<ival, vector<ival>, decltype(cmp)> running(cmp);

        int i = 0;
        for (const auto& iv : times)
        {
            while (!running.empty() && running.top().end <= iv[0])
            {
                const int chair = running.top().chair;
                running.pop();
                free.push(chair);
            }

            int assn = -1;
            if (!free.empty())
            {
                assn = free.top();
                free.pop();
            }
            else
            {
                assn = running.size();
            }
                
            running.push(ival{.start=iv[0], .end=iv[1], .chair=assn});
            if (indices[i] == targetFriend)
            {
                return assn;
            }
            ++i;
        }

        throw std::runtime_error("very descriptive error");
    }
};
