class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        ind = collections.defaultdict(int)
        for (f, t) in paths:
            ind[t] += 1
            ind[f] -= 1
        return next(k for k, v in ind.items() if v == 1)

