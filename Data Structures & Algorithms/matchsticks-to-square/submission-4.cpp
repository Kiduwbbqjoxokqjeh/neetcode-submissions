class Solution {
public: 
    using vi = vector<int>;
    bool func(vi &side,vi &match,int tar,int idx)
    {
        if(idx == match.size())
        {
            return all_of(side.begin(),side.end(),[&](int x){
                return x == tar;
            });
        }
        for(int i=0;i<side.size();i++)
        {
            if(side[i] + match[idx] <= tar)
            {
                side[i] += match[idx];
                if(func(side,match,tar,idx+1)) return true;
                side[i] -= match[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(sum%4 != 0) return false;
        vi side(4,0);
        int tar = sum/4;
        return func(side,matchsticks,tar,0);
    }
};