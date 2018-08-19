class AllOne {
private:
    map<string, int> items;
    map<int, set<string>> cnts;

public:
    /** Initialize your data structure here. */
    AllOne() {
        items.clear();
        cnts.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int pre = items[key]++;
        if (pre > 0) {
            cnts[pre].erase(key);
            if (cnts[pre].size() == 0)
                cnts.erase(pre);
        }
        cnts[pre + 1].insert(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (items.find(key) == items.end())
            return;
        int pre = items[key]--;
        cnts[pre].erase(key);
        if (cnts[pre].size() == 0)
            cnts.erase(pre);
        if (pre == 1)
            items.erase(key);
        else
            cnts[pre - 1].insert(key);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        auto it = cnts.rbegin();
        if (it == cnts.rend())
            return "";
        return *it->second.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        auto it = cnts.begin();
        if (it == cnts.end())
            return "";
        return *it->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
