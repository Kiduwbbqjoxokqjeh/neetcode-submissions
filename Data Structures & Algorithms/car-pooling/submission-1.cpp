class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001,0);
        for(auto &trip:trips)
        {
            int from,to,passenger;
            from=trip[1];
            to=trip[2];
            passenger=trip[0];
            diff[from] += passenger;
            diff[to] -= passenger;
        }
        int total=0;
        for(auto &count : diff)
        {
            total += count;
            if(total > capacity) return false;
        }
        return true;
    }
};