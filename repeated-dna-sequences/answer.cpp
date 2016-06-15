#define i64 long long
#define MOD 1000000000LL

class Solution {
private:
    int charToInt(char c) {
        if (c == 'A')
            return 0;
        else if (c == 'C')
            return 1;
        else if (c == 'G')
            return 2;
        else
            return 3;
    }

    char intToChar(int i) {
        if (i == 0)
            return 'A';
        else if (i == 1)
            return 'C';
        else if (i == 2)
            return 'G';
        else
            return 'T';
    }

    string convert(i64 value) {
        string dna = "";
        for (int i = 0; i < 10; ++i) {
            dna = dna + intToChar(value % 10);
            value /= 10;
        }
        reverse(dna.begin(), dna.end());
        return dna;
    }

    vector<string> solve(map<i64, int>& counter) {
        vector<string> dna;
        map<i64, int>::iterator it;
        for (it = counter.begin(); it != counter.end(); it++) {
            if (it->second <= 1)
                continue;
            dna.push_back(convert(it->first));
        }
        return dna;
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length(), i = 0;
        i64 hash = 0;
        map<i64, int> counter;
        while (i < 10 && i < n)
            hash = hash * 10 + charToInt(s[i++]);
        counter[hash]++;
        while (i < n) {
            hash = (hash % MOD) * 10 + charToInt(s[i++]);
            counter[hash]++;
        }
        return solve(counter);
    }
};