class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = blocks.size();
        for(int i=0;i<=n-k;i++)
        {
            int cw=0;
            for(int j=i;j<i+k;j++)
            {
                if(blocks[j] == 'W') cw++;
            }
            ans = min(ans,cw);
        }
        return ans;
    }
};