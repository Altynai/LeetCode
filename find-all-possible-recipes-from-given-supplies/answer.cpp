class Solution {
public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    int n = ingredients.size();
    unordered_set<string> had(supplies.begin(), supplies.end());

    auto canCreate = [&](int i) -> bool {
      if (had.size() < ingredients[i].size())
        return 0;
      for (string &s : ingredients[i]) {
        if (had.count(s) == 0)
          return 0;
      }
      return 1;
    };

    unordered_set<int> ids;
    for (int i = 0; i < n; i++)
      ids.insert(i);

    while (ids.size()) {
      int cnt = 0;
      auto it = ids.begin();
      while (it != ids.end()) {
        int i = *it;
        if (canCreate(i)) {
          had.insert(recipes[i]);
          cnt++;
          it = ids.erase(it);
        } else {
          it++;
        }
      }
      if (cnt == 0)
        break;
    }

    vector<string> ans;
    for (string &s : recipes) {
      if (had.count(s))
        ans.push_back(s);
    }
    return ans;
  }
};
