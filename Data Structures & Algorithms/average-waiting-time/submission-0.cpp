class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        long long  t=0,s=0;

        for(auto x:customers)
        {
            int arrival = x[0], cook = x[1];
            if(t < arrival) t = arrival;

            t += cook;
            s += (t - arrival);
        }
        return (double)s/customers.size();
        
    }
};