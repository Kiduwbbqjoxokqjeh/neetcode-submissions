class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        int n = chars.size();
        int i=0;
        while(i<n)
        {
            s += chars[i];
            int j=i+1;
            while(j<n and chars[j] == chars[i])
            {
                j++;
            }
            if(j-i > 1) s += to_string(j-i);
            i=j;
        }
        for(int i=0;i<s.size();i++)
        {
            chars[i] = s[i];
        }
        return s.size();
    }
};