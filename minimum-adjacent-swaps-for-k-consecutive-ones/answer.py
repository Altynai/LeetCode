class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        if k == 1:
            return 0

        n = len(nums)
        l = collections.deque()
        r = collections.deque()
        lsum = rsum = 0
        ans = math.inf

        for i, val in enumerate(nums):
            if val == 1:
                r.append(i)
                rsum += i
                
                # keep balance
                while len(r) + len(l) > k:
                    assert(l)
                    lsum -= l.popleft()

                while len(r) - len(l) >= 2:
                    x = r.popleft()
                    rsum -= x
                    l.append(x)
                    lsum += x

            if len(l) + len(r) == k:
                assert(len(r) == len(l) + k % 2)
                if k % 2 == 1:
                    y = r[0]
                    x = y - 1
                else:
                    x = (l[-1] + r[0]) // 2
                    y = x + 1

                ansl = (x - len(l) + 1 + x) * len(l) // 2 - lsum
                ansr = rsum - (y + y + len(r) - 1) * len(r) // 2
                ans = min(ans, ansl + ansr)
        
        return ans
 
