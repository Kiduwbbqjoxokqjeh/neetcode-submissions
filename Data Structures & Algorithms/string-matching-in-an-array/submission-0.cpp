class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(), [](string a,string b){
            return a.size() < b.size();
        });
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(words[j].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
        
    }
};