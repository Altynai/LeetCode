class Solution:
    
    MOUSE = 0
    CAT = 1

    DRAW = 0
    MOUSE_WINNER = 1
    CAT_WINNER = 2

    def __dfs(self, mouse, cat, step):
        if step >= len(self.graph):
            return self.DRAW

        key = (mouse, cat, step)
        value = self.cache.get(key)
        if value is not None:
            return value

        if mouse == 0:
            self.cache[key] = self.MOUSE_WINNER
            return self.MOUSE_WINNER
        elif mouse == cat:
            self.cache[key] = self.CAT_WINNER
            return self.CAT_WINNER

        if step % 2 == 0:
            return self.__mouse_move(mouse, cat, step)
        else:
            return self.__cat_move(mouse, cat, step)

    def __mouse_move(self, mouse, cat, step):
        key = (mouse, cat, step)
        draw = False

        for nxt in self.graph[mouse]:
            if nxt == 0:
                self.cache[key] = self.MOUSE_WINNER
                return self.MOUSE_WINNER
            elif nxt == cat:
                continue

            predict = self.__dfs(nxt, cat, step + 1)
            if predict == self.MOUSE_WINNER:
                self.cache[key] = self.MOUSE_WINNER
                return self.MOUSE_WINNER
            elif predict == self.DRAW:
                draw = True

        choice = self.DRAW if draw else self.CAT_WINNER
        self.cache[key] = choice
        return choice

    def __cat_move(self, mouse, cat, step):
        key = (mouse, cat, step)
        draw = False
        for nxt in self.graph[cat]:
            # it is not allowed for the Cat to travel to the Hole (node 0.)
            if nxt == 0:
                continue
            elif nxt == mouse:
                self.cache[key] = self.CAT_WINNER
                return self.CAT_WINNER

            predict = self.__dfs(mouse, nxt, step + 1)
            if predict == self.CAT_WINNER:
                self.cache[key] = self.CAT_WINNER
                return self.CAT_WINNER
            elif predict == self.DRAW:
                draw = True

        choice = self.DRAW if draw else self.MOUSE_WINNER
        self.cache[key] = choice
        return choice

    def catMouseGame(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        self.graph = graph
        self.cache = {}
        return self.__dfs(1, 2, 0)

