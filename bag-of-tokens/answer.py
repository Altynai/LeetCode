class Solution:
    def bagOfTokensScore(self, tokens, P):
        """
        :type tokens: List[int]
        :type P: int
        :rtype: int
        """        
        tokens.sort()
        i, j = 0, len(tokens) - 1
        point, ans = 0, 0

        while i <= j:
            if P >= tokens[i]:
                P -= tokens[i]
                i += 1
                point += 1
                ans = max(ans, point)

            elif point > 0:
                P += tokens[j]
                j -= 1;
                point -= 1
            
            else:
                break
        
        return ans

