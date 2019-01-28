class TimeMap {
private:
    unordered_map<string, map<int, string> > s;

public:
    /** Initialize your data structure here. */
    TimeMap() {
        s.clear();
    }
    
    void set(string key, string value, int timestamp) {
        s[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto i = s.find(key);
        if (i == s.end())
            return "";

        map<int, string>& m = i->second;
        auto j = m.lower_bound(timestamp);
        if (j != m.end() && j->first == timestamp)
            return j->second;
        else if (j != m.begin()) {
            j--;
            return j->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
