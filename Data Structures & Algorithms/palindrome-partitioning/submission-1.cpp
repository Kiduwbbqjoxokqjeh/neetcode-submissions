class Solution {
public:
    using vs = vector<string>;
    vector<vs> ans;
    bool ispal(string &s,int l,int r)
    {
        while(l<r)
        {
            if(s[l] != s[r]) return false;
            l++;r--;
        }
        return true;
    }
    void solve(string &s,vs &path,int idx)
    {
        if(idx == s.size()) 
        {
            ans.push_back(path);return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(ispal(s,idx,i))
            {
                path.push_back(s.substr(idx,i-idx+1));
                solve(s,path,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vs path;
        solve(s,path,0);
        return ans;
    }
};
