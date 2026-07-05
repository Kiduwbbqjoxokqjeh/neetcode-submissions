class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n= words.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        {
            string x = words[i];
            int xs = x.size();
            if((string("aeiou").find(x[0]) != string::npos) and (string("aeiou").find(x[xs-1]) != string::npos))
            {
                v[i] = 1;
            }
            // 1 0 1 1 1
        }

        vector<int> ans;

        for(auto x:queries)
        {
            int l = x[0],r = x[1];
            int s = accumulate(v.begin()+l , v.begin()+r+1, 0);
            ans.push_back(s);
        }
        return ans;
        
    }
};