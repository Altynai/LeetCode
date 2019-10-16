class Solution(object):

    delta = (
        (0, 1, 0, -1, 1, 1, -1, -1),
        (1, 0, -1, 0, 1, -1, 1, -1),
    )

    def queensAttacktheKing(self, queens, king):
        """
        :type queens: List[List[int]]
        :type king: List[int]
        :rtype: List[List[int]]
        """
        queens = set(tuple(xy) for xy in queens)
        ans = []
        for dx, dy in zip(self.delta[0], self.delta[1]):
            x, y = king
            while 0 <= x < 8 and 0 <= y < 8:
                if (x, y) in queens:
                    ans.append([x, y])
                    break
                x += dx
                y += dy
        return ans

