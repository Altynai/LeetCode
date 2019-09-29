class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = collections.deque()
        for ch in s:
            if stack and stack[-1][0] == ch:
                count = stack[-1][1] + 1
                if count == k:
                    stack.pop()
                else:
                    stack[-1] = (ch, count)
            else:
                stack.append((ch, 1))
        return "".join(ch * count for (ch, count) in stack)

