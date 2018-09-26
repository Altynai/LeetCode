class TopVotedCandidate {
private:
    int n;
    map<int, int> count;
    map<int, set<int>> ms;
    map<int, int> recent;
    map<int, int> leader;

    void incr(int person, int time, int when) {
        auto it = count.find(person);
        if (it == count.end()) {
            count[person] = 1;
            ms[1].insert(person);
        } else {
            int pre = it->second;
            it->second += 1;
            set<int>& persons = ms[pre];
            persons.erase(person);
            if (persons.empty())
                ms.erase(pre);
            ms[pre + 1].insert(person);
        }
        recent[person] = when;
    }

    int get() {
        auto it = ms.rbegin();
        set<int>& persons = it->second;
        bool first = true;
        int who = -1, when = -1;
        for (int person : persons) {
            int when2 = recent[person];
            if (first || when2 > when) {
                who = person;
                when = when2;
            }
            first = false;
        }
        return who;
    }

public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        count.clear();
        recent.clear();
        ms.clear();
        leader.clear();
        
        n = persons.size();
        for (int i = 0; i < n; i++) {
            incr(persons[i], times[i], i);
            leader[times[i]] = get();
        }
    }
    
    int q(int t) {
        auto it = leader.upper_bound(t);
        if (it == leader.end())
            return (leader.rbegin())->second;
        --it;
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
