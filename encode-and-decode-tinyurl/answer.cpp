#define uint_64 unsigned long long
const string alphabets = "abcdefghijklmnopqrstuvwxyz"\
                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"\
                         "0123456789";

class Solution {
private:
    string hash(const string& longUrl) {
        uint_64 ans = 0, hash = 330110293;
        for (int i = 0; i < longUrl.size(); i++)
            ans = ans * hash + longUrl[i];
        char buff[64];
        int i = 0;
        for (i = 0; i < 63 && ans > 1; ++i) {
            buff[i] = alphabets[ans % 62];
            ans /= 62;
        }
        buff[i + 1] = '\0';
        return string(buff, buff + i);
    }

    map<string, string> db;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = hash(longUrl);
        db[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return db[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));