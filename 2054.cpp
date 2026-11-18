class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end(), [](const auto& i, const auto& j) {
            return std::tie(i[0], i[1]) < std::tie(j[0], j[1]);
        });

        auto cmp = [](const auto& i, const auto& j) {
            return i[1] > j[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        int max_val = 0; 
        int champ = events[0][2];

        for (auto i = 0; i < events.size(); ++i)
        {
            while (pq.size() && pq.top()[1] < events[i][0])
            {
                max_val = std::max(max_val, pq.top()[2]);
                pq.pop();
            }

            champ = std::max(champ, max_val + events[i][2]);
            pq.push(events[i]);
        }

        return champ;
    }
};
