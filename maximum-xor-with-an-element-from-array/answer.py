class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        root = [None, None]

        def insert(num):
            cur = root
            for i in range(29, -1, -1):
                p = (num >> i) & 1
                if not cur[p]:
                    cur[p] = [None, None]
                cur = cur[p]
        
        def answer(x, m):
            cur = root
            for i in range(29, -1, -1):
                p = (x >> i) & 1
                if cur[p ^ 1]:
                    q = p ^ 1
                elif cur[p]:
                    q = p
                else:
                    return -1
                cur = cur[q]
                if q == 1:
                    x ^= (1 << i)
            return x

        nums.sort()
        n = len(nums)

        q = [(m, x, i) for i, (x, m) in enumerate(queries)]
        q.sort()
        ans = [-1 for _ in range(len(q))]
        
        j = 0
        for (m, x, i) in q:
            while j < n and nums[j] <= m:
                insert(nums[j])
                j += 1
            ans[i] = answer(x, m)

        return ans
