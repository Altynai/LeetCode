class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> s_counter, g_counter;
        int sn = secret.length(), gn = guess.length();
        int bulls = 0;
        for (int i = 0; i < min(sn , gn); ++i) {
            s_counter[secret[i]]++;
            g_counter[guess[i]]++;
            if (secret[i] == guess[i])
                bulls++;
        }
        int cows = 0;
        for (char c = '0'; c <= '9'; c++)
            cows += std::min(s_counter[c], g_counter[c]);
        return std::to_string(bulls) + "A" + std::to_string(cows - bulls) + "B";
    }
};