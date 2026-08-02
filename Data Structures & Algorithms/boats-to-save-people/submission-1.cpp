class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size(),ans=0;
        int i=0,j=n-1;
        while(i<j)
        {
            int total = people[i]+people[j];
            if(total <= limit)
            {
                ans++;i++;j--;
            }
            else
            {
                if(people[j] <= limit)ans++;
                j--;
            }
        }
        if(i==j) ans++;
        return ans;
    }
};