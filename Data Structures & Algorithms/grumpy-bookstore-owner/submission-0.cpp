class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied=0;
        int n = customers.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        {
            if(grumpy[i] == 0)
            {
                satisfied += customers[i]; // these many customers are satisfied
            }
            else v[i] = customers[i];
        }
        // 0 0 0 2 0 1 0 5 find the subarray whose length is "minutes" whose sum is maximum
        int sum=0;
        int maxsum=0;
        for(int i=0;i<minutes;i++)
        {
            sum += v[i];
        }
        maxsum = max(maxsum,sum);
        for(int i=minutes;i<n;i++)
        {
            sum += v[i];
            sum -= v[i-minutes];
            maxsum = max(sum,maxsum);
        }
        return satisfied + maxsum;
    }
};