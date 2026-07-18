class Solution {
public:
    using vi = vector<int>;
    bool func(vi &m,vi &side,int tar,int idx)
    {
        if(idx == m.size())
        {
            return all_of(side.begin(),side.end(),[&](int x){
                return x == tar;
            });
        }
        for(int i=0;i<side.size();i++)
        {
            if(side[i] + m[idx] <= tar)
            {
                side[i] += m[idx];
                if(func(m,side,tar,idx+1)) return true;
                side[i] -= m[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(),matchsticks.rend());
        int x = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(x%4 != 0) return false;
        int tar = x/4;
        vi side(4,0);
        return func(matchsticks,side,tar,0);
    }
};