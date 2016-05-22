class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> answer;
        if (n1 == 0 || n2 == 0)
            return answer;
        vector<int> &small = n1 < n2 ? nums1 : nums2;
        vector<int> &large = n1 < n2 ? nums2 : nums1;
        map<int, int> counter;
        for (int i = 0; i < small.size(); ++i)
            counter[small[i]]++;
        for (int i = 0; i < large.size(); ++i) {
            map<int, int>::iterator it = counter.find(large[i]);
            if (it != counter.end() && it->second > 0) {
                answer.push_back(large[i]);
                it->second -= 1;
            }
        }
        return answer;
    }
};