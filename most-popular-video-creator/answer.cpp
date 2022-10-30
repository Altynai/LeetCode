template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  vector<vector<string>> mostPopularCreator(vector<string> &creators,
                                            vector<string> &ids,
                                            vector<int> &views) {
    int n = creators.size();

    map<string, int64> sum;
    map<string, pair<int, string>> videos;
    int64 most = 0;
    for (int i = 0; i < n; i++) {
      umax(most, sum[creators[i]] += views[i]);
      if (videos.count(creators[i])) {
        auto [cnt, id] = videos[creators[i]];
        if (views[i] > cnt or (views[i] == cnt and ids[i] < id))
          videos[creators[i]] = {views[i], ids[i]};
      } else
        videos[creators[i]] = {views[i], ids[i]};
    }

    vector<vector<string>> ans;
    for (auto &[k, v] : sum) {
      if (v == most) {
        ans.push_back({k, videos[k].second});
      }
    }
    return ans;
  }
};
