
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > result;
        std::sort(num.begin(), num.end());
        set<vector<int> > cache;
        int store[4] = {0};

        for (int i = 0; i < n; i++) {
            store[0] = num[i];
            for (int j = i + 1; j < n; j++) {
                store[1] = num[j];
                int base_sum = num[i] + num[j];
                int start = j + 1, end = n - 1;
                while (start < end) {
                    int current_sum = base_sum + num[start] + num[end];
                    if (current_sum == target) {
                        store[2] = num[start], store[3] = num[end];
                        vector<int> answer(store, store + 4);
                        cache.insert(answer);
                        start++, end--;
                    } else if (current_sum < target)
                        start++;
                    else
                        end--;
                }
            }
        }
        for (set<vector<int> >::iterator i = cache.begin(); i != cache.end(); i++)
            result.push_back(*i);
        return result;
    }
};

