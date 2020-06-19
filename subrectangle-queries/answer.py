class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.r = rectangle
        self.ops = []

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        self.ops.append((row1, row2, col1, col2, newValue))

    def getValue(self, row: int, col: int) -> int:
        n = len(self.ops)
        for i in range(n - 1, -1, -1):
            r1, r2, c1, c2, val = self.ops[i]
            if r1 <= row <= r2 and c1 <= col <= c2:
                return val
        return self.r[row][col]


# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)
