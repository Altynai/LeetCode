class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        q = collections.deque([(-1, 0)])
        ans = sum = 0
        for i, a in enumerate(A):
            sum += a
            while q:
                index = i - q[0][0]
                delta = sum - q[0][1]
                if index - delta <= K:
                    break
                q.popleft()
            q.append((i, sum))
            ans = max(ans, i - q[0][0])
        return ans

