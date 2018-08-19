
class Solution:
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        n = len(image)
        m = len(image[0])
        oldColor = image[sr][sc]
        image[sr][sc] = newColor
        q = collections.deque([(sr, sc)])
        dx = [0, 1, 0, -1]
        dy = [-1, 0, 1, 0]
        vis = set()
        vis.add((sr, sc))
        while q:
            (i, j) = q.popleft()
            for di, dj in zip(dx, dy):
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= n or nj < 0 or nj >= m:
                    continue
                if (ni, nj) not in vis and image[ni][nj] == oldColor:
                    vis.add((ni, nj))
                    image[ni][nj] = newColor
                    q.append((ni, nj))
        return image

