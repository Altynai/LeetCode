class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0)
            return vector<int>();
        int cursor1 = 0, cursor2 = 0;
        set<int> bucket;
        while (cursor1 < n1 && cursor2 < n2) {
            if (nums1[cursor1] == nums2[cursor2]) {
                bucket.insert(nums1[cursor1]);
                cursor1++, cursor2++;
            } else if (nums1[cursor1] < nums2[cursor2])
                cursor1++;
            else
                cursor2++;
        }
        return vector<int>(bucket.begin(), bucket.end());
    }
};