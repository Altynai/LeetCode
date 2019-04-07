class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        dq = collections.deque()
        ans = []
        for i, ch in enumerate(S):
            if ch == ')':
                j, _ = dq.pop()
                if len(dq) == 0:
                    ans.append(S[j + 1:i])
            else:
                dq.append((i, ch))
        return "".join(ans)

