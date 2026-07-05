class Solution {
public:
    int maxDifference(string s) {

        sort(s.begin(),s.end());
        int f = 1;
        vector<int> x;
        for(int i=1;i<s.size();i++)
        {
            if(s[i] == s[i-1])
            {
                f++;
            }
            else
            {
                x.push_back(f);
                f = 1;
            }
        }
        x.push_back(f);
        // 5 2 1
        int mo = INT_MIN, me = INT_MAX;
        for(auto a: x)
        {
            if(a%2 != 0)
            {
                mo = max(mo,a);
            }
            else me = min(me,a);
        }
        if(mo != INT_MIN and me != INT_MAX) return mo-me;
        return 0;
    }
};