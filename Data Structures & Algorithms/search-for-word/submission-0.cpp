class Solution {
public:
    bool func(vector<vector<char>> &b,int i,int j,string &word,int k)
    {
        if(k==word.size()) return true;
        if(i<0 or i>=b.size() or j<0 or j>=b[0].size()) return false;
        if(b[i][j] != word[k]) return false;
        char ch = b[i][j];
        b[i][j] = '#';
        bool x = func(b,i+1,j,word,k+1);
        bool y = func(b,i-1,j,word,k+1);
        bool a = func(b,i,j+1,word,k+1);
        bool c = func(b,i,j-1,word,k+1);
        bool found = (x or y or a or c);
        b[i][j] = ch;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(func(board,i,j,word,0)) return true;
            }
        }
        return false;
    }
};
