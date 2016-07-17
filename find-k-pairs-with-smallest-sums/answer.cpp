#define i64 long long

bool compare(const pair<int, int>& lh, const pair<int, int>& rh) {
    i64 lsum = (i64)lh.first + lh.second;
    i64 rsum = (i64)rh.first + rh.second;
    if (lsum != rsum)
        return lsum < rsum;
    return lh < rh;
}

class Solution {
private:
    i64 count(vector<int>& nums1, vector<int>& nums2, i64 threshold) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int>::iterator it;
        i64 count = 0;
        for (int i = 0; i < n1; ++i) {
            it = std::upper_bound(nums2.begin(), nums2.end(), threshold - nums1[i]);
            count += (i64)(it - nums2.begin());
        }
        return count;
    }

    i64 findThreshold(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        i64 low = (i64)nums1[0] + nums2[0];
        i64 high = (i64)nums1[n1 - 1] + nums2[n2 - 1];
        i64 mid = 0, answer = 0;
        while (low <= high) {
            mid = (low + high) >> 1;
            i64 c = count(nums1, nums2, mid);
            if (c >= k) {
                answer = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return answer;
    }

public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<pair<int, int> > answer;
        if (n1 == 0 || n2 == 0)
            return answer;
        k = min((i64)k, (i64)n1 * n2);
        i64 threshold = findThreshold(nums1, nums2, k);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if ((i64)nums1[i] + nums2[j] <= threshold) {
                    answer.push_back(make_pair(nums1[i], nums2[j]));
                }
            }
        }
        sort(answer.begin(), answer.end(), compare);
        while (answer.size() > k)
            answer.pop_back();
        return answer;
    }
};