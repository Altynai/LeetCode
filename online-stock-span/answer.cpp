#define N 100

struct Bucket {
    vector<int> b;
    int mx;
    
    Bucket(int i) {
        b = vector<int>(1, i);
        mx = i;
    }

    int size() {
        return b.size();
    }

    void push_back(int i) {
        b.push_back(i);
        mx = max(mx, i);
    }
    
    int lessOrEqual(int i) {
        int j = size() - 1;
        while (j >= 0 && i >= b[j])
            j--;
        return size() - j - 1;
    }
};

class StockSpanner {
private:
    vector<Bucket> buckets;

public:
    StockSpanner() {
        buckets.clear();
    }
    
    int next(int price) {
        int cnt = 1, i = buckets.size() - 1;
        while (i >= 0 && price >= buckets[i].mx) {
            cnt += buckets[i].size();
            i--;
        }
        if (i >= 0 && price < buckets[i].mx)
            cnt += buckets[i].lessOrEqual(price);
    
        if (buckets.empty() || buckets.back().size() == N) {
            buckets.push_back(Bucket(price));
        } else {
            buckets.back().push_back(price);
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
