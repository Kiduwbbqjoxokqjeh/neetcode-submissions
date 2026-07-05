class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto x:arr1) mp[x]++;

        vector<int> ans;
        for(auto x:arr2)
        {
            while(mp[x]--) {ans.push_back(x);}
            mp.erase(x);
        }
        for(auto &[k,v]:mp) 
        {
            while(v--)
            {
                ans.push_back(k);
            }
        }
        return ans;
        
    }
};