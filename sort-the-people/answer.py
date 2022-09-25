class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        pairs = [(hei, name) for (hei, name) in zip(heights, names)]
        pairs.sort(reverse=True)
        return [pr[1] for pr in pairs]
