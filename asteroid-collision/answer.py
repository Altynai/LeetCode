class Solution:
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        n = len(asteroids)
        if n == 0:
            return []

        pos = collections.deque()
        cnt = [0] * n
        for i in range(n):
            if asteroids[i] > 0:
                pos.append(i)
                continue
            while pos:
                j = pos[-1]
                if asteroids[j] > -asteroids[i]:
                    cnt[i] = 1
                    break
                elif asteroids[j] == -asteroids[i]:
                    cnt[i] = 1
                    cnt[j] = 1
                    pos.pop()
                    break
                else:
                    cnt[j] = 1
                    pos.pop()
        return [asteroids[i] for i in range(n) if cnt[i] == 0]

