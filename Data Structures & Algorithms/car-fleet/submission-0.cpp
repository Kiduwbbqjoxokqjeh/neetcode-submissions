class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        int n = speed.size();
        for(int i=0;i<n;i++)
        {
            double t = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],t});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,double>>());
        stack<double> st;
        for(auto &car:cars)
        {
            if(st.empty() or car.second > st.top())
            {
                st.push(car.second);
            }
        }
        return st.size();
    }
};
