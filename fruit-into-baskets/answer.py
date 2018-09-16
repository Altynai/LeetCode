class Solution(object):
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        seen = {}
        n = len(tree)
        i, j = 0, 0
        elements = collections.deque()
        ans = 0

        def ok(element):
            if len(seen) == 2:
                return element in seen
            return len(seen) < 2

        while j < n:
            if j < n and ok(tree[j]):
                k = tree[j]
                seen[k] = seen.get(k, 0) + 1
                j += 1
                ans = max(ans, j - i)
            else:
                k = tree[i]
                seen[k] -= 1
                if seen[k] == 0:
                    del seen[k]
                i += 1
        return ans

