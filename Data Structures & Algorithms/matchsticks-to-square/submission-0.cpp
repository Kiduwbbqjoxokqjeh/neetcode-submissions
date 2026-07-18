class Solution {
public:
    bool func(vector<int> &m,vector<int> &side,int tar,int idx)
    {
        if(idx == m.size())
        {
           return (all_of(side.begin(),side.end(),[&](int x){
            return x == tar;
           }));
        }
        for(int i=0;i<4;i++)
        {
            if(side[i] + m[idx] <= tar)
            {
                side[i] += m[idx];
                if( func(m,side,tar,idx+1)) return true;
                side[i] -= m[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int x = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(x%4 != 0) return false;
        int tar = x/4;
        vector<int> side(4,0);
        return func(matchsticks,side,tar,0);   
    }
};