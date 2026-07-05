class Solution {
public:

    string encode(vector<string>& strs) {

        string ans = "";
        for(auto x: strs)
        {
            ans += to_string(x.size()) + "#" + x;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.size())
        {
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i,j-i));
            string word = s.substr(j+1,len);
            ans.push_back(word);
            i = j+len+1;
        }
        return ans;
    }
};
