#include <string>
#include <cassert>
#include <stack>
#include <vector>

using namespace std;

#define N 26

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        if (n == 0)
            return "";
        bool visited[N];
        memset(visited, false, sizeof(visited));
        int count[N] = {0};
        for (int i = 0; i < n; ++i)
            count[s[i] - 'a']++;
        stack<char> letters;
        for (int i = 0; i < n; ++i) {
            count[s[i] - 'a']--;
            if (visited[s[i] - 'a'])
                continue;
            while (!letters.empty() && s[i] < letters.top() && count[letters.top() - 'a'] > 0) {
                visited[letters.top() - 'a'] = false;
                letters.pop();
            }
            letters.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        vector<char> chs(letters.size());
        for (int i = letters.size() - 1; i >= 0; --i) {
            chs[i] = letters.top();
            letters.pop();
        }
        return string(chs.begin(), chs.end());
    }
};

int main(int argc, char const *argv[]) {
    Solution *s = new Solution();
    assert(s->removeDuplicateLetters("bacdb") == "acdb");
    assert(s->removeDuplicateLetters("abacb") == "abc");
    assert(s->removeDuplicateLetters("acabc") == "abc");
    assert(s->removeDuplicateLetters("cbacdcbc") == "acdb");
    assert(s->removeDuplicateLetters("bcabc") == "abc");
    assert(s->removeDuplicateLetters("aaczads") == "aczds");
    return 0;
}