class Solution:
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        deck.sort(reverse=True)
        q = collections.deque()
        for card in deck:
            q.rotate()
            q.appendleft(card)
        return list(q)
                
