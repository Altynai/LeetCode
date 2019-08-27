class Solution:

    def count(self, value, fs):
        l, r, index = 0, len(fs) - 1, -1
        while l <= r:
            mid = (l + r) >> 1
            if fs[mid] > value:
                index, r = mid, mid - 1
            else:
                l = mid + 1
        return 0 if index == -1 else len(fs) - index

    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        fs = [word.count(min(word)) for word in words]
        fs.sort()
        return [self.count(query.count(min(query)), fs) for query in queries]

