class Solution:
    def numSteps(self, s: str) -> int:
        step = 0
        while s != "1":
            n = len(s)
            if s[n - 1] == "0":
                s = s[:n - 1]
            else:
                idx = s.rfind("0")
                if idx == -1:
                    s = "1" + "0" * n
                else:
                    t = list(s)
                    t[idx] = "1"
                    for j in range(idx + 1, n):
                        t[j] = "0"
                    s = ''.join(t)
            step += 1
        return step

