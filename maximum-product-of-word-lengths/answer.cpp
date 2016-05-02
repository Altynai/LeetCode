class Solution {
private:
    int string2Int(const string& word) {
        int answer = 0;
        for (int i = 0; i < word.size(); ++i)
            answer |= 1 << (word[i] - 'a');
        return answer;
    }
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        std::vector<int> integers;
        for (int i = 0; i < n; ++i)
            integers.push_back(this->string2Int(words[i]));
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((integers[i] | integers[j]) == integers[i] + integers[j])
                    answer = std::max(answer, (int)words[i].size() * (int)words[j].size());
            }
        }
        return answer;
    }
};