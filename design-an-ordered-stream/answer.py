class OrderedStream:

    def __init__(self, n: int):
        self.n = n
        self.ptr = 1
        self.s = [None for _ in range(n + 1)]

    def insert(self, x: int, value: str) -> List[str]:
        self.s[x] = value
        
        ans = []
        x = self.ptr
        while x <= self.n and self.s[x] is not None:
            ans.append(self.s[x])
            x += 1
        
        if ans:
            self.ptr = x
        return ans


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(id,value)
