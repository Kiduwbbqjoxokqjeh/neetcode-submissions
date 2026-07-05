class Solution {
public:
    int maxScore(string s) {

        int maxe = -1;
        for(int i=0;i<s.size();i++)
        {
            if(i == 0) continue;

            string left = s.substr(0,i);
            string right = s.substr(i,s.size());

            int z = count(left.begin(),left.end(),'0');
            int o = count(right.begin(),right.end(),'1');

            int total = z+o;
            maxe = max(maxe,total);
        }
        return maxe;
        
    }
};