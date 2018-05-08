struct Node {
    int frequency;
    string word;

    Node(int f, string s):frequency(f), word(s){}

    friend bool operator<(const Node& lh, const Node& rh) {
        if (lh.frequency != rh.frequency)
            return lh.frequency > rh.frequency;
        return lh.word < rh.word;
    }
};

class Solution {
private:
    vector<Node> hp;
    map<string, int> counter;

    void init() {
        hp.clear();
        counter.clear();
    }
    
    void count(vector<string>& words) {
        for (string word : words)
            counter[word]++;
    }

    vector<string> solve(int k) {
        vector<string> ans;
        for (auto it = counter.begin(); it != counter.end(); it++) {
            Node node(it->second, it->first);
            hp.push_back(node);
            push_heap(hp.begin(), hp.end());
            if (hp.size() > k) {
                pop_heap(hp.begin(), hp.end());
                hp.pop_back();
            }
        }
        while (hp.size()) {
            ans.push_back(hp[0].word);
            pop_heap(hp.begin(), hp.end());
            hp.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        init();
        count(words);
        return solve(k);
    }
};