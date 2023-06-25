class Solution {
public:
  vector<int> survivedRobotsHealths(vector<int> &positions,
                                    vector<int> &healths, string directions) {
    int n = positions.size();
    vector<pair<int, int>> robots(n);
    for (int i = 0; i < n; i++)
      robots[i] = {positions[i], i};
    sort(robots.begin(), robots.end());

    stack<int> ids;
    for (int i = 0; i < n; i++) {
      int j = robots[i].second;
      if (directions[j] == 'R')
        ids.push(j);
      else {
        while (!ids.empty() and healths[j] > 0) {
          int k = ids.top();
          if (healths[j] == healths[k])
            healths[j] = healths[k] = 0;
          else if (healths[j] > healths[k])
            healths[k] = 0, healths[j]--;
          else
            healths[k]--, healths[j] = 0;

          if (healths[k] == 0)
            ids.pop();
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (healths[i] > 0)
        ans.push_back(healths[i]);
    }
    return ans;
  }
};
