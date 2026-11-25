class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int fst_water_end = INT_MAX; 
        for (int i = 0; i < waterStartTime.size(); ++i) 
        {
            fst_water_end = std::min(fst_water_end, waterStartTime[i] + waterDuration[i]);
        }
        
        int fst_land_end = INT_MAX; 
        for (int i = 0; i < landStartTime.size(); ++i) 
        {
            fst_land_end = std::min(fst_land_end, landStartTime[i] + landDuration[i]);
        }

        int earliest_finish = INT_MAX;
        for (int i = 0; i < landStartTime.size(); ++i) 
        {
            const int start = std::max(landStartTime[i], fst_water_end);
            earliest_finish = std::min(earliest_finish, start + landDuration[i]);
        }
        
        for (int i = 0; i < waterStartTime.size(); ++i) 
        {
            const int start = std::max(waterStartTime[i], fst_land_end);
            earliest_finish = std::min(earliest_finish, start + waterDuration[i]);
        }

        return earliest_finish;
    }
};
