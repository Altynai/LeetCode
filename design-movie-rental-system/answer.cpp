class MovieRentingSystem {
private:
  map<pair<int, int>, int> p;             // (shop, movie), price
  map<int, set<pair<int, int>>> unrented; // movie, (price, shop)
  map<int, set<pair<int, int>>> rented;   // price, (shop, movie)
  int n;

public:
  MovieRentingSystem(int _n, vector<vector<int>> &entries) {
    unrented.clear();
    rented.clear();
    p.clear();
    n = _n;
    for (auto &e : entries) {
      int shop = e[0], movie = e[1], price = e[2];
      p[{shop, movie}] = price;
      unrented[movie].emplace(price, shop);
    }
  }

  vector<int> search(int movie) {
    vector<int> ans;
    int k = 5;
    auto it = unrented[movie].begin();
    while (k > 0 && it != unrented[movie].end()) {
      ans.push_back(it->second);
      k--;
      it++;
    }
    return ans;
  }

  void rent(int shop, int movie) {
    int price = p[{shop, movie}];
    unrented[movie].erase({price, shop});
    rented[price].emplace(shop, movie);
  }

  void drop(int shop, int movie) {
    int price = p[{shop, movie}];
    rented[price].erase({shop, movie});
    unrented[movie].emplace(price, shop);
  }

  vector<vector<int>> report() {
    vector<vector<int>> ans;
    int k = 5;
    for (auto &[price, items] : rented) {
      for (auto [shop, movie] : items) {
        if (k > 0) {
          ans.push_back({shop, movie});
          k--;
        } else {
          break;
        }
      }
      if (k == 0)
        break;
    }
    return ans;
  }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
