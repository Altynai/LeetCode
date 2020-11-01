class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        v, h = destination
        n = v + h

        ans = ""
        for i in range(n):
            m = n - 1 - i
            cnt = 1 if m == 0 or v == 0 else math.comb(m, v)
            
            if k > cnt and v > 0:
                ans += "V"
                k -= cnt
                v -= 1
            elif h > 0:
                ans += "H"
                h -= 1
            else:
                ans += "V"
                v -= 1
        
        return ans

