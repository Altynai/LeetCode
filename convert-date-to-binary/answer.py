class Solution:
    def convertDateToBinary(self, date: str) -> str:
        nums = map(int, date.split('-'))
        strs = map(lambda x: format(x, 'b'), nums)
        return '-'.join(strs)

