class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        chars = [[a, 'a'], [b, 'b'], [c, 'c']]
        chars.sort(reverse=True)
        s = []

        found = True
        while found:
            found = False
            for i, (num, ch) in enumerate(chars):
                if num > 0 and (len(s) < 2 or s[-2] != ch or s[-1] != ch):
                    found = True
                    s.append(ch)
                    chars[i][0] -= 1
                    break
            chars.sort(reverse=True)

        return ''.join(s)

