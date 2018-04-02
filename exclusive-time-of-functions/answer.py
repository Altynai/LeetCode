class Stack(object):
    def __init__(self):
        self.stack = []
        self.size = 0
    
    def push(self, item):
        if self.size >= len(self.stack):
            self.stack.append(item)
        else:
            self.stack[self.size] = item
        self.size += 1
    
    def pop(self):
        if self.size <= 0:
            return None
        item = self.stack[self.size - 1]
        self.size -= 1
        return item

    def top(self):
        if self.size <= 0:
            return None
        return self.stack[self.size - 1]


class Solution(object):
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        times = [0 for _ in xrange(n)]
        stack = Stack()
        lastTime = 0
        for log in logs:
            funcId, operation, time = log.split(":")
            funcId, time = int(funcId), int(time)
            # start
            # 1. get `funcId` from stack top, add $.start - current
            # 2. set current = $.start
            # 3. push to stack
            if operation == "start":
                if stack.size > 0:
                    times[stack.top()] += time - lastTime
                lastTime = time
                stack.push(funcId)
            # end
            # 1. get `funcId` from stack top, add $.end + 1 - current
            # 2. set current = $.end + 1
            # 3. pop stack
            else:
                if stack.size > 0:
                    times[stack.top()] += time + 1 - lastTime
                lastTime = time + 1
                stack.pop()
        return times
