class RandomizedSet {
private:
    vector<int> vr;
    map<int, int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        vr.clear();
        mp.clear();
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = mp.find(val);
        if (it != mp.end())
            return false;
        vr.push_back(val);
        mp[val] = vr.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = mp.find(val);
        if (it == mp.end())
            return false;
        int idx = it->second, n = vr.size();
        vr[idx] = vr[n - 1];
        mp[vr[idx]] = idx;
        vr.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vr[rand() % vr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */