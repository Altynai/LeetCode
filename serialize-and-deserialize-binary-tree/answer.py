# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Container:
    
    def __init__(self):
        self.nums = {}
    
    def set(self, idx, val):
        self.nums[idx] = val

    def serialize(self):
        return json.dumps(self.nums)
    
    @classmethod
    def create_from(cls, data):
        c = cls()
        c.nums = json.loads(data)
        return c

    def rebuild(self, idx):
        key = str(idx)
        if key not in self.nums:
            return None
        root = TreeNode(self.nums[key])
        root.left = self.rebuild(idx << 1)
        root.right = self.rebuild((idx << 1) + 1)
        return root


class Codec:

    def dfs(self, root, idx, container):
        if root is not None:
            container.set(idx, root.val)
            self.dfs(root.left, idx << 1, container)
            self.dfs(root.right, (idx << 1) + 1, container)

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        container = Container()
        self.dfs(root, 1, container)
        return container.serialize()

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        c = Container.create_from(data)
        return c.rebuild(1)
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))