class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        unordered_map<char,int> m1,m2;
        for(auto x:words[0]) m1[x]++;

        for(int i=1;i<words.size();i++)
        {
            m2.clear();
            for(auto x:words[i]) m2[x]++;


            for(auto it= m1.begin();it!=m1.end();)
            {
                char k = it->first;
                if(m2.count(k))
                {
                    it->second = min(it->second,m2[k]);
                    it++;
                }
                else it = m1.erase(it);
            }
        }
        vector<string> ans;
        for(auto &[k,v]: m1)
        {
            while(v--)
            {
                ans.push_back(string(1,k));
            }
        }
        return ans;
        
    }
};