class Solution(object):
    def hash(self, word):
        n = len(word)
        a = [word[i] for i in xrange(0, n, 2)]
        b = [word[i] for i in xrange(1, n, 2)]
        a.sort()
        b.sort()
        return ("".join(a), "".join(b))

    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        return len(set(self.hash(word) for word in A))

