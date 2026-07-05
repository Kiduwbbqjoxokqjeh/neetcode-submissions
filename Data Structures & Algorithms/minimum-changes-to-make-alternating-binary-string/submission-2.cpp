class Solution {
public:
    int minOperations(string s) {

        int x=0,y=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] != (i%2 == 0 ? '0': '1')) x++;

            if(s[i] != (i%2 == 0 ? '1': '0')) y++;
        }
        return min(x,y);
        
    }
};