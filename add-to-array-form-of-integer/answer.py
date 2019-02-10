class Solution:
    def addToArrayForm(self, A: 'List[int]', K: 'int') -> 'List[int]':
        b = int(''.join(map(str, A))) + K
        return list(map(int, str(b)))

