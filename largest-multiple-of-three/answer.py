class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        ans, r1, r2 = [], [], []
        for d in digits:
            if d % 3 == 0:
                ans.append(d)
            else:
                r1.append(d) if d % 3 == 1 else r2.append(d)
        
        r1.sort()
        r2.sort()
        while len(r1) > 3:
            ans.extend(r1[-3:])
            r1 = r1[:-3]
        while len(r2) > 3:
            ans.extend(r2[-3:])
            r2 = r2[:-3]

        mx, r3 = 0, []
        for i in range(len(r1) + 1):
            for j in range(len(r2) + 1):
                if i == j or (i == 0 and j == 3) or (i == 3 and j == 0):
                    l = i + j
                    tmp = ([] if i == 0 else r1[-i:]) + ([] if j == 0 else r2[-j:])
                    tmp.sort(reverse=True)
                    if l > mx or (l == mx and tmp > r3):
                        mx = l
                        r3 = tmp
        
        ans.extend(r3)
        ans.sort(reverse=True)
        if not ans:
            return ""
        s = "".join(map(str, ans)).lstrip("0")
        return s if s else "0"

