class Solution {
public:
    bool possible(vector<int> &piles,int h,int k)
    {
        int hours=0;
        for(auto &x:piles)
        {
            hours += (x+k-1)/k;
        }
        return (hours <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r = *max_element(piles.begin(),piles.end());
        while(l<r)
        {
            int mid = (l+r)/2;
            if(possible(piles,h,mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
