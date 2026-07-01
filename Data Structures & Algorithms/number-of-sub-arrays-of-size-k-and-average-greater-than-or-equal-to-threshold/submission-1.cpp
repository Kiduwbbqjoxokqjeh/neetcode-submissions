class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum=0,ans=0;
        for(int i=0;i<k;i++) sum += arr[i];
        if(sum >= k*threshold) ans++;
        for(int i=k;i<n;i++)
        {
            sum += arr[i];
            sum -= arr[i-k];

            if(sum >= k*threshold)ans++;
        }
        return ans;
    }
};