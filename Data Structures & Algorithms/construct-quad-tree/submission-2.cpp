/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node *solve(vector<vector<int>> &grid,int r,int c,int size)
    {
        bool same=true;
        int val=grid[r][c];
        for(int i=r;i<r+size;i++)
        {
            for(int j=c;j<c+size;j++)
            {
                if(grid[i][j]!=val)
                {
                    same=false;
                    break;
                }
            }
            if(!same)break;
        }
        if(same) return new Node(val,true);
        int half=size/2;
        Node *tl,*tr,*bl,*br;
        tl = solve(grid,r,c,half);
        tr = solve(grid,r,c+half,half);
        bl = solve(grid,r+half,c,half);
        br = solve(grid,r+half,c+half,half);
        return new Node(true,false,tl,tr,bl,br);
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,0,grid.size());
    }
};















