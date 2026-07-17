class Solution {
public:
    using vs = vector<string>;
    vs ans;
    void func(string &curr,int open,int closed,int n)
    {
        if(curr.size() == 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
        {
            curr.push_back('(');
            func(curr,open+1,closed,n);
            curr.pop_back();
        }
        if(closed<open)
        {
            curr.push_back(')');
            func(curr,open,closed+1,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr;
        func(curr,0,0,n);
        return ans;
    }
};
