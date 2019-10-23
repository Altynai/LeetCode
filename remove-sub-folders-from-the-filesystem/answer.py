class Node:
    
    def __init__(self):
        self.flag = False
        self.children = {}

class Solution:
    
    def conflict(self, root, names):
        cur = root
        for name in names:
            if name not in cur.children:
                return False
            elif cur.children[name].flag:
                return True
            cur = cur.children[name]
        return False

    def insert(self, root, names):
        cur = root
        for name in names:
            if name not in cur.children:
                cur.children[name] = Node()
            cur = cur.children[name]
        cur.flag = True

    def dfs(self, root, prefix):
        if root.flag:
            self.ans.append(prefix)
            return
        for name, node in root.children.items():
            self.dfs(node, prefix + '/' + name)

    def removeSubfolders(self, folder: List[str]) -> List[str]:
        root = Node()
        folder.sort()
        for path in folder:
            names = path.split('/')[1:]
            if not self.conflict(root, names):
                self.insert(root, names)
        
        self.ans = []
        self.dfs(root, '')
        return self.ans

