bool validChar(const char& chr) {
    return chr == '\n' || chr == '\t';
}

struct Word {
    string name;
    int level;
    int length;
    bool isFile;

    Word(const string& input, int& index) {
        name = "";
        level = 0;
        length = 0;
        isFile = false;

        int n = input.size();
        // read \n\t
        while (index < n && validChar(input[index])) {
            if (input[index] == '\t')
                level++;
            index++;
        }
        // read file name
        while (index < n && !validChar(input[index])) {
            name = name + input[index];
            if (input[index] == '.')
                isFile = true;
            index++;
        }
        length = name.size();
    }
};

class Solution {

public:
    stack<Word> words;

    int lengthLongestPath(string input) {
        int ans = 0, index = 0, n = input.size();
        if (n == 0)
            return ans;
        while (!words.empty())
            words.pop();
        int currentLength = 0;
        while (index < n) {
            Word word(input, index);
            while (!words.empty() && word.level <= words.top().level) {
                currentLength -= words.top().length;
                words.pop();
            }
            words.push(word);
            currentLength += word.length;
            if (word.isFile) {
                int length = currentLength + words.size() - 1;
                ans = max(length, ans);
            }
        }
        return ans;
    }
};
