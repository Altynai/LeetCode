class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return;
        sort(nums.begin(), nums.end());
        vector<int> backup(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        for (int k = 0; k < n;) {
            nums[k++] = backup[i++];
            if (k < n)
                nums[k++] = backup[j--];
        }
    }
};