from itertools import chain

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        nodes = set(range(n))
        for c in chain(leftChild, rightChild):
            nodes.discard(c)

        if len(nodes) != 1:
            return False

        root = nodes.pop()
        seen = set()

        def dfs(i):
            if i == -1:
                return True
            elif i in seen:
                return False

            seen.add(i)
            return dfs(leftChild[i]) and dfs(rightChild[i])

        return dfs(root)

