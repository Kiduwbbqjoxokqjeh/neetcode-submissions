class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(string x:details)
        {
            string y = x.substr(11,2);
            int z = stoi(y);
            if(z > 60) ans++;
        }
        return ans;
        
    }
};