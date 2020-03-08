class Solution:
    def generateTheString(self, n: int) -> str:
        return 'a' * n if n % 2 == 1 else 'a' * (n - 1) + 'b'

