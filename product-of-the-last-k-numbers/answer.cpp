class ProductOfNumbers {
private:
    int n;
    map<int, vector<int>> seen;

public:
    ProductOfNumbers() {
        n = 0;
        seen.clear();
    }
    
    void add(int num) {
        seen[num].push_back(n++);
    }
    
    int getProduct(int k) {
        k = n - k;
        int ans = 1;
        for (const pair<int, vector<int>>& item : seen) {
            int d = distance(lower_bound(item.second.begin(), item.second.end(), k), item.second.end());
            if (item.first == 0 && d > 0)
                return 0;
            else if (item.first > 1)
                ans *= (int)pow(item.first, d);
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
