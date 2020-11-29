class FrontMiddleBackQueue:

    def __init__(self):
        self.l = collections.deque()
        self.r = collections.deque()

    def balance(self):
        # from r to l
        while len(self.r) and len(self.r) > len(self.l) + 1:
            self.l.append(self.r.popleft())
            
        # from l to r
        while len(self.l) and len(self.l) > len(self.r):
            self.r.appendleft(self.l.pop())
        
        assert(len(self.l) == len(self.r) or len(self.l) + 1 == len(self.r))

    def pushFront(self, val: int) -> None:
        self.l.appendleft(val)
        self.balance()

    def pushMiddle(self, val: int) -> None:
        self.l.append(val)
        self.balance()

    def pushBack(self, val: int) -> None:
        self.r.append(val)
        self.balance()

    def popFront(self) -> int:
        x = -1
        if self.l:
            x = self.l.popleft()
        elif self.r:
            x = self.r.popleft()
        self.balance()
        return x

    def popMiddle(self) -> int:
        if len(self.l) == len(self.r):
            x = self.l.pop() if self.l else -1
        else:
            x = self.r.popleft() if self.r else -1
        self.balance()
        return x

    def popBack(self) -> int:
        x = -1
        if self.r:
            x = self.r.pop()
        elif self.l:
            x = self.l.pop()
        self.balance()
        return x


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()
