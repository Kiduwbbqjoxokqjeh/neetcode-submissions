class Solution {
public:
    string largestNumber(vector<int>& nums) {

        // 3 30 34 5 9
        // 3 5 9 30 34

        // 9534330

        // 9,5,34,3,30
        // 9 5 3  34 30
        //  9534330

        vector<string> v;
        for(auto x:nums) v.push_back(to_string(x));
        
        sort(v.begin(),v.end(),[](string &a,string &b){
            return a+b > b+a ;
        });

        if(v[0] == "0") return "0";

        string ans;
        for(auto s:v) ans += s;
        return ans;
        

        
    }
};