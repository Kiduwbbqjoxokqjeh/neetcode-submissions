class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> t;
        for(int i=0;i<=rowIndex;i++)
        {
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++)
            {
                row[j] = t[i-1][j] + t[i-1][j-1];
            }
            t.push_back(row);
        }

        return t[rowIndex];
        
        
    }
};