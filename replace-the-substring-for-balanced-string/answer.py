import collections

class Solution:
    
    def valid(self, counter, extra):
        return all(counter.get(char, 0) >= cnt for char, cnt in extra.items())

    def balancedString(self, s: str) -> int:
        n = len(s)
        m = n // 4
        extra = {
            k: v
            for k, v in (collections.Counter(s) - collections.Counter(Q=m, W=m, E=m, R=m)).items()
            if v > 0
        }
        if not extra:
            return 0
        
        counter = collections.defaultdict(int)
        ans = -1
        i = 0
        for j, char in enumerate(s):
            counter[char] += 1
            while i <= j and self.valid(counter, extra):
                l = j - i + 1
                if ans == -1 or l < ans:
                    ans = l
                counter[s[i]] -= 1
                i += 1
        return ans

