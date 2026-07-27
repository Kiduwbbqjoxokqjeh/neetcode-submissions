class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        if(dead.count("0000")) return -1;
        unordered_set<string> vis;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        vis.insert("0000");
        while(!q.empty())
        {
            string curr = q.front().first;
            int moves=q.front().second;q.pop();
            if(curr == target) return moves;
            for(int i=0;i<4;i++)
            {
                string next = curr;
                next[i] = (curr[i] == '9')? '0':curr[i]+1;
                if(!dead.count(next) and !vis.count(next))
                {
                    q.push({next,moves+1});
                    vis.insert(next);
                }
                next = curr;
                next[i] = (curr[i] == '0')?'9':curr[i]-1;
                if(!dead.count(next) and !vis.count(next))
                {
                    q.push({next,moves+1});
                    vis.insert(next);
                }
            }
        }
        return -1;
    }
};