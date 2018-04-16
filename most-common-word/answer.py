class Solution(object):
    def toLowerCase(self, word):
        return word.lower()

    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        words = paragraph.split(" ")
        banned = set(self.toLowerCase(word) for word in banned)
        counter = collections.defaultdict(int)
        for word in words:
            word = word.rstrip("!?',;. ")
            if not word:
                continue
            word = self.toLowerCase(word)
            if word in banned:
                continue
            counter[word] += 1
        ans, best = "", 0
        for word, times in counter.iteritems():
            if times > best:
                best = times
                ans = word
        return ans