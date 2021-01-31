class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        e = collections.defaultdict(list)
        n = len(adjacentPairs) + 1
        
        for u, v in adjacentPairs:
            e[u].append(v)
            e[v].append(u)
        
        fst = next(u for u, vs in e.items() if len(vs) == 1)
        seen = set([fst])
        ans = [fst]
        
        for i in range(n - 1):
            nxt = next(v for v in e[fst] if v not in seen)
            seen.add(nxt)
            ans.append(nxt)
            fst = nxt
        
        return ans
