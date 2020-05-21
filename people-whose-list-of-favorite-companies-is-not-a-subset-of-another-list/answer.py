class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        sets = [set(fc) for fc in favoriteCompanies]
        ans = []
        for i, fi in enumerate(sets):
            isSubSet = False
            for j, fj in enumerate(sets):
                if i == j:
                    continue
                if fi & fj == fi:
                    isSubSet = True
                    break
            if not isSubSet:
                ans.append(i)
        return ans

