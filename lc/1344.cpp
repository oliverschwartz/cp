class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hang = 0.5 * minutes + (hour != 12 ? (hour * 30.0): 0);
        double mang = 6.0 * minutes;
        double diff = std::abs(mang - hang); 
        return diff > 180.0 ? 360.0 - diff : diff;
    }
};
