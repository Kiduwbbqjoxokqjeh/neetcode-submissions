class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<set<char>> row(9),col(9),box(9);

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.') continue;
                char c = board[i][j];
                int bi = (i/3)*3 + (j/3);
                if(row[i].count(c) or col[j].count(c) or box[bi].count(c)) return false;

                row[i].insert(c);col[j].insert(c);box[bi].insert(c);
            }
        }
        return true;
        
    }
};
