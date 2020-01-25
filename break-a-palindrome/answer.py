class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        chars = list(palindrome)
        n = len(chars)
        for i in range(n):
            if (n % 2 == 0 or i != n // 2) and chars[i] != "a":
                chars[i] = "a"
                return "".join(chars)
        if len(chars) > 1:
            chars[-1] = "b"
            return "".join(chars)
        return ""

