class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        obstacles = set(tuple(_) for _ in obstacles)
        x, y = (0, 0)
        ans = 0
        direction = 0
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        for command in commands:
            if command == -1:
                direction = (direction + 1) % 4
            elif command == -2:
                direction = (direction - 1 + 4) % 4
            else:
                for i in xrange(command):
                    nx = x + dx[direction]
                    ny = y + dy[direction]
                    if (nx, ny) in obstacles:
                        break
                    x, y = nx, ny
                    ans = max(ans, x * x + y * y)
        return ans

