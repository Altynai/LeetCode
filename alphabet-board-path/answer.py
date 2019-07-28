class Solution(object):
    def where(self, char):
        diff = ord(char) - ord('a')
        x = diff // 5
        return (x, diff - x * 5)

    def path(self, from_, to):
        (x0, y0), (x1, y1) = self.where(from_), self.where(to)
        return ('D' if x0 < x1 else 'U') * abs(x0 - x1) + \
            ('R' if y0 < y1 else 'L') * abs(y0 - y1)

    def alphabetBoardPath(self, target):
        """
        :type target: str
        :rtype: str
        """
        n = len(target)
        ans = []
        from_ = 'a'
        for to in target:
            if from_ != to:
                if from_ == 'z':
                    ans.append('U' + self.path('u', to))
                elif to == 'z':
                    ans.append(self.path(from_, 'u') + 'D')
                else:
                    ans.append(self.path(from_, to))
            ans.append('!')
            from_ = to
        return ''.join(ans)

