class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        target = set(target)
        n = max(target)
        ans = []
        for i in range(1, n + 1):
            ans.append("Push")
            if i not in target:
                ans.append("Pop")
        return ans

