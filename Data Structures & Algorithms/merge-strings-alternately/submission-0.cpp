class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        string ans;
        int i=0,j=0;
        while(i<n and j<m)
        {
            ans += word1[i++];
            ans += word2[j++];
        }
        if(i<n)
        {
            ans += word1.substr(i);
        }
        if(j<m)
        {
            ans += word2.substr(j);
        }
        return ans;
    }
};