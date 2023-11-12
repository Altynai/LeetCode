class Solution {
public:
  vector<string> findHighAccessEmployees(vector<vector<string>> &access_times) {
    map<string, vector<int>> m;
    // int n = access_times.size();
    for (auto &record : access_times) {
      string t = record[1];
      int hour = (t[0] - '0') * 10 + (t[1] - '0');
      int minute = (t[2] - '0') * 10 + (t[3] - '0');
      m[record[0]].push_back(hour * 60 + minute);
    }

    vector<string> ans;
    for (auto &[name, times] : m) {
      sort(times.begin(), times.end());
      int n = times.size();
      for (int i = 0, j = 0; i < n; i++) {
        while (j < n and times[j] < times[i] + 60)
          j++;
        if (j - i >= 3) {
          ans.push_back(name);
          break;
        }
      }
    }
    return ans;
  }
};
