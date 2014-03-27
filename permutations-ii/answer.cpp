
class Solution {
private:
    int *nums;
    int n;
    int *choice;
    bool *used;

    void init(vector<int> &num) {
        n = num.size();
        std::sort(num.begin(), num.end());
        nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = num[i];
        choice = new int[n];
        memset(choice, 0, sizeof(int) * n);
        used = new bool[n];
        memset(used, 0, sizeof(bool) * n);
    }

    void dfs(vector<vector<int> > &result, int index) {
        if (index == n) {
            result.push_back(vector<int>(choice, choice + n));
            return;
        }
        int *pre_choice = NULL;
        for (int i = 0; i < n; i++) {
            if (used[i] || (pre_choice && nums[i] == *pre_choice))
                continue;
            used[i] = true;
            choice[index] = nums[i];
            pre_choice = &nums[i];
            dfs(result, index + 1);
            used[i] = false;
        }
    }

public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        init(num);
        vector<vector<int> >result;
        dfs(result, 0);
        return result;
    }
};
