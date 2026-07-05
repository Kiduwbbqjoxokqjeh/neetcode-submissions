class Solution {
public:
    bool isPathCrossing(string path) {

        set<pair<int,int>> st;
        int x=0,y=0;
        st.insert({0,0});

        for(auto c:path)
        {
            if(c == 'N') y++;
            else if(c == 'S') y--;
            else if(c == 'E') x++;
            else if(c == 'W') x--;

            if(st.count({x,y})) return true;
            st.insert({x,y});
        }
        return false;
        
    }
};