class Solution {
public:
    vector<int> p;
    int total;
    Solution(vector<int>& w) {
        total=0;
        for(auto &x:w)
        {
            total += x;
            p.push_back(total);
        }
    }
    
    int pickIndex() {
        int num = rand()%total + 1;
        return lower_bound(p.begin(),p.end(),num) - p.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */