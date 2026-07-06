class Solution {
public:
    bool poss(vector<int> &w,int days,int k)
    {
        int cnt=1,sum=0;
        for(auto &x:w)
        {
            if(sum + x<= k) sum += x;
            else
            {
                cnt++;sum=x;
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        while(l<r)
        {
            int mid = (l+r)/2;
            if(poss(weights,days,mid)) r=mid;
            else l=mid+1;
        }   
        return l;
    }
};