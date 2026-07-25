class Solution {
public:
    int n ,m;
    using vi=vector<int>;
    using vc=vector<char>;
    void dfs(int i,int j,vector<vc> &board)
    {
        board[i][j] = '#';
        vector<vi> v = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &d:v)
        {
            int nx = i+d[0],ny = j+d[1];
            if(nx>=0 and nx<n and ny>=0 and ny<m and board[nx][ny] == 'O')
            {
                dfs(nx,ny,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();m=board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[0][i] == 'O') dfs(0,i,board);
            if(board[n-1][i] == 'O') dfs(n-1,i,board);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0] == 'O') dfs(i,0,board);
            if(board[i][m-1] == 'O') dfs(i,m-1,board);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }

    }
};

















