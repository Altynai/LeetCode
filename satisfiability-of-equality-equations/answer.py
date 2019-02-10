class DSU:
    
    def __init__(self, chars):
        self.fa = {c:c for c in chars}

    def find(self, x):
        r = x
        while self.fa[r] != r:
            r = self.fa[r]
        i = x
        while i != r:
            i, self.fa[i] = self.fa[i], r
        return r
    
    def join(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x != y:
            self.fa[x] = y


class Solution:
    def equationsPossible(self, equations: 'List[str]') -> 'bool':
        chars = set()
        for e in equations:
            chars.add(e[0])
            chars.add(e[3])
        
        dsu = DSU(chars)
        for e in equations:
            if e[1] == '=':
                dsu.join(e[0], e[3])

        for e in equations:
            if e[1] == '=':
                continue
            if dsu.find(e[0]) == dsu.find(e[3]):
                return False
        return True

