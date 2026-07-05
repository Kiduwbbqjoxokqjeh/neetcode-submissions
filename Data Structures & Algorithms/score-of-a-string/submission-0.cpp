class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.size();i++)
        {
            int x = int(s[i]),y = int(s[i-1]);
            ans += abs(x-y);
        }
        return ans;
        
    }
};