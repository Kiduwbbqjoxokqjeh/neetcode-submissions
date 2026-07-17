class Solution {
public:
    bool func(vector<vector<char>> &b,string &word,int i,int j,int k)
    {
        if(k==word.size()) return true;
        if(i<0 or i>=b.size() or j<0 or j>=b[0].size()) return false;
        if(b[i][j] != word[k]) return false;
        bool p,q,r,s;
        char ch = b[i][j];
        b[i][j] = '#';
        p = func(b,word,i+1,j,k+1);
        q = func(b,word,i-1,j,k+1);
        r = func(b,word,i,j+1,k+1);
        s = func(b,word,i,j-1,k+1);
        b[i][j] = ch;
        return (p or q or r or s);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(func(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
