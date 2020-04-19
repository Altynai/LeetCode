class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        arr = list(range(1, m + 1))
        idx = {v: i for i, v in enumerate(arr)}
        ans = []
        for val in queries:
            p = idx[val]
            ans.append(p)
            for i in range(p - 1, -1, -1):
                idx[arr[i]], idx[arr[i + 1]] = idx[arr[i + 1]], idx[arr[i]]
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
        return ans

