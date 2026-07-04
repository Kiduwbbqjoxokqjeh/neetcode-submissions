class Solution {
public:
    //dead cant fight
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto &x:asteroids)
        {
            bool alive=true;
            while(alive and !st.empty() and st.top()>0 and x<0)
            {
                if(st.top() < -x)
                {
                    st.pop();
                }
                else if(st.top() == -x)
                {
                    st.pop();
                    alive=false;
                }
                else alive=false;
            }
            if(alive) st.push(x);
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};