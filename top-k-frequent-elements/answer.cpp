#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define PII pair<int, int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        std::priority_queue<PII, std::vector<PII >, std::greater<PII > > queue;
        int count = 1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1])
                count++;
            else {
                queue.push(make_pair(count, nums[i - 1]));
                count = 1;
                if (queue.size() > k)
                    queue.pop();
            }
        }
        queue.push(make_pair(count, nums[n - 1]));
        if (queue.size() > k)
            queue.pop();
        std::vector<int> answer(k);
        for (int i = 0 ; i < k; i++){
            answer[k - i - 1] = queue.top().second;
            queue.pop();
        }
        return answer;
    }
};

int main(int argc, char const *argv[]) {
    int p[6] = {1, 1, 1, 2, 2, 3};
    std::vector<int> nums(p, p + 6);
    // for (int i : {1, 1, 1, 2, 2, 3})
    //     nums.push_back(i);
    Solution* solution = new Solution();
    nums = solution->topKFrequent(nums, 2);
    for (int i = 0; i < nums.size(); i++)
        printf("%d ", nums[i]);
    return 0;
}