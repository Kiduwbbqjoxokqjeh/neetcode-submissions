class RandomizedSet {
public:
    vector<int> a;
    set<int> b;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(b.count(val)) return false;
        else
        {
            a.push_back(val);
            b.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {

        auto it = find(a.begin(),a.end(),val);
        if(it == a.end()) return false;
        a.erase(it);
        b.erase(val);
        return true;
    }
    
    int getRandom() {

        int n = a.size();
        int idx = rand() % n;
        return a[idx];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */