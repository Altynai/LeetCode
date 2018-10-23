class Solution:

    def __process(self, s):
        items = []
        ch = s[0]
        cnt = 1
        n = len(s)

        for i in range(1, n):
            if ch == s[i]:
                cnt += 1
            else:
                items.append((ch, cnt))
                ch = s[i]
                cnt = 1
        
        return items
        
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        a = self.__process(name)
        b = self.__process(typed)
        if len(a) != len(b):
            return False
        
        for ((ch1, cnt1), (ch2, cnt2)) in zip(a, b):
            if ch1 != ch2 or cnt1 > cnt2:
                return False

        return True

