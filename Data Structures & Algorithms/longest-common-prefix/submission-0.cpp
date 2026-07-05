class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string x = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            while(strs[i].find(x) != 0) 
            {
                x.pop_back();
                if(x.empty()) return "";
            }
        }
        return x;
        
    }
};