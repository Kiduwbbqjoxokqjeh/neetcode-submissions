class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int mid = num/2;
        for(int i=1;i<=mid;i++)
        {
            if(i*i == num) return true;
        }
        return false;
    }
};