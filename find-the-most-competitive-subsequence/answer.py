class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        dq = collections.deque()
        n = len(nums)
        rem = n - k

        for val in nums:
            dq.append(val)
            while rem > 0 and len(dq) >= 2 and dq[-1] < dq[-2]:
                x = dq.pop()
                dq.pop()
                dq.append(x)
                rem -= 1

        while len(dq) > k:
            dq.pop()

        return list(dq)

