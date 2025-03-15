class Spreadsheet:

    def __init__(self, rows: int):
        self.n = rows
        self.values = {}

    def setCell(self, cell: str, value: int) -> None:
        col = ord(cell[0]) - ord('A')
        row = int(cell[1:])
        self.values.setdefault(col, {})
        self.values[col][row] = value

    def resetCell(self, cell: str) -> None:
        self.setCell(cell, 0)

    def getValue(self, formula: str) -> int:
        x, y = formula[1:].split("+")
        res = int(x) if x[0].isdigit() else self.__getCell(x)
        res += int(y) if y[0].isdigit() else self.__getCell(y)
        return res
        
    def __getCell(self, cell: str) -> int:
        col = ord(cell[0]) - ord('A')
        row = int(cell[1:])
        return self.values.get(col, {}).get(row, 0)

# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)
