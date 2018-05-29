/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

int matches(const string& lh, const string& rh) {
    int m = 0, n = std::min(lh.size(), rh.size());
    for (int i = 0; i < n; i++)
        m += lh[i] == rh[i] ? 1 : 0;
    return m;
}

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        set<string> words;
        int n = wordlist.size(), ans = wordlist[0].size();
        for (string& word : wordlist)
            words.insert(word);
        for (int i = 0; i < 10 && !words.empty(); i++) {
            auto it = words.begin();
            string word = *it;
            int m = master.guess(word);
            if (m == ans)
                break;

            it = words.begin();
            while (it != words.end()) {
                if (matches(*it, word) != m)
                    it = words.erase(it);
                else
                    it++;
            }
        }
    }
};
