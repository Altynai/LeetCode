from collections import defaultdict

class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        ans = []
        seen = set()
        ids = defaultdict(int)
        for name in names:
            if name in seen:
                k = ids[name] + 1
                while f'{name}({k})' in seen:
                    k += 1
                ids[name] = k
                name = f'{name}({k})'
            seen.add(name)
            ans.append(name)
        return ans

