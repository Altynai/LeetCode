class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        h = {ch: 0 for ch in "croak"}
        h[""] = 0

        for ch in croakOfFrogs:
            if ch == "c":
                if h[""] > 0:
                    h[""] -= 1
                h["c"] += 1
            else:
                pre = {
                    "r": "c",
                    "o": "r",
                    "a": "o",
                    "k": "a",
                }[ch]
                if h[pre] == 0:
                    return -1
                else:
                    h[pre] -= 1
                    h[ch] += 1
                    if ch == "k":
                        h[ch] -= 1
                        h[""] += 1
        return -1 if any(h[ch] > 0 for ch in "croak") else h[""]

