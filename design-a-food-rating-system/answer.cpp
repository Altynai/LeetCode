class FoodRatings {
private:
  map<string, int> rating;
  map<string, string> type;
  map<string, multiset<pair<int, string>>> ranking;

public:
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    int n = foods.size();
    for (int i = 0; i < n; i++) {
      rating[foods[i]] = ratings[i];
      type[foods[i]] = cuisines[i];
      ranking[cuisines[i]].insert({-ratings[i], foods[i]});
    }
  }

  void changeRating(string food, int newRating) {
    auto it = rating.find(food);
    multiset<pair<int, string>> &ms = ranking[type[food]];
    if (it != rating.end()) {
      int old = it->second;
      ms.erase(ms.find({-old, food}));
    }
    rating[food] = newRating;
    ms.insert({-newRating, food});
  }

  string highestRated(string cuisine) {
    auto it = ranking.find(cuisine);
    return it->second.begin()->second;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
