#define N 16

class Solution {
private:
    int array[N], top;
    set<vector<int> > collection;

    void dfs(vector<int>& nums, int index) {
        int n = nums.size();
        if (n == index) {
            if (top >= 2)
                collection.insert(vector<int>(array, array + top));
            return;
        }
        // not choose
        dfs(nums, index + 1);
        // choose
        if (top == 0 || nums[index] >= array[top - 1]) {
            array[top++] = nums[index];
            dfs(nums, index + 1);
            top--;
        }
    }

public:
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        collection.clear();
        top = 0;
        int n = nums.size();
        if (n == 0)
            return vector<vector<int> >();
        dfs(nums, 0);
        return vector<vector<int> >(collection.begin(), collection.end());
    }
};