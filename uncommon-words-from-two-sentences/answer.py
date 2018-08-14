class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        counter = collections.defaultdict(int)
        for w in A.split(" "):
            counter[w] += 1
        for w in B.split(" "):
            counter[w] += 1
        return [
            w for w, c in counter.iteritems()
            if c == 1
        ]
