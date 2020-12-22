class Solution:
    def reformatNumber(self, n: str) -> str:
        n = n.replace(' ', '').replace('-', '')
        ans = []
        while len(n) > 4:
            ans.append(n[:3])
            n = n[3:]
        
        if len(n) == 4:
            ans.append(n[:2])
            ans.append(n[2:])
        else:
            ans.append(n)
        
        return "-".join(ans)

