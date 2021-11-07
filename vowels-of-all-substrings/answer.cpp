class Solution {
public:
  long long countVowels(string s) {
    int n = s.size();
    const string vowels = "aeiou";
    long long ans = 0;
    for (int i = 0; i < n; i++)
      if (vowels.find(s[i]) != -1)
        ans += 1LL * (i + 1) * (n - i);
    return ans;
  }
};
