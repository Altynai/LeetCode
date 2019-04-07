class Solution:
    def match(self, query: str, pattern: str) -> bool:
        j, m = 0, len(query)
        for i, ch in enumerate(pattern):
            found = False
            if ch.isupper():
                while j < m and not found:
                    if query[j].isupper():
                        if query[j] == ch:
                            found = True
                        else:
                            return False
                    j += 1
            else:
                while j < m and not found:
                    if query[j].isupper():
                        return False
                    elif query[j] == ch:
                        found = True
                    j += 1

            if not found:
                return False

        return True if j == m else query[j:].islower()

    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        return [self.match(query, pattern) for query in queries]

