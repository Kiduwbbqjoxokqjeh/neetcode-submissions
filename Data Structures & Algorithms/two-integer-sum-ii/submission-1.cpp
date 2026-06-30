class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // unordered_map<int,int> mp;
        // int n = numbers.size();
        // for(int i=0;i<n;i++)
        // {
        //     int tmp = target-numbers[i];
        //     if(mp.count(tmp))
        //     {
        //         return  {mp[tmp],i+1};
        //     }
        //     mp[numbers[i]] = i+1;
        // }
        // return {};
        

        int l=0,r=numbers.size()-1;
        while(l<r)
        {
            int sum = numbers[l]+numbers[r];
            if(sum > target) r--;
            else if(sum < target) l++;
            else return {l+1,r+1};
        }
    }
};
