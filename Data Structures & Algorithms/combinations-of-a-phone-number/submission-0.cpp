class Solution {
public:
    using vs = vector<string>;
    vs ans;
    void solve(int idx,string &digits,string &curr,vs &mp)
    {
        if(idx == digits.size())
        {
            ans.push_back(curr);
            return;
        }
        string letters = mp[digits[idx] - '0'];
        for(char ch:letters)
        {
            curr.push_back(ch);
            solve(idx+1,digits,curr,mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mp =
        {
            "",     //0
            "",     //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz"  //9
        };
        string curr = "";
        solve(0,digits,curr,mp);
        return ans;

    }
};
