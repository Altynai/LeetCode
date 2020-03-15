class CustomStack:

    def __init__(self, maxSize: int):
        self.arr = []
        self.m = maxSize
        self.n = 0

    def push(self, x: int) -> None:
        if self.n >= self.m:
            return
        if self.n >= len(self.arr):
            self.arr.append(x)
        else:
            self.arr[self.n] = x
        self.n += 1

    def pop(self) -> int:
        if self.n == 0:
            return -1
        v = self.arr[self.n - 1]
        self.n -= 1
        return v

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, self.n)):
            self.arr[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
