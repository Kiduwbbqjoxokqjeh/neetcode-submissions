class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        set<string> st;
        for(auto s:emails)
        {
            size_t atpos = s.find("@");
            string local = s.substr(0,atpos);
            string domain = s.substr(atpos);

            size_t ppos = local.find("+");
            if(ppos != string::npos)
            {
                local = local.substr(0,ppos);
            }

            local.erase(remove(local.begin(),local.end(),'.'),local.end());
            st.insert(local+domain);
        }
        return st.size();
        
    }
};