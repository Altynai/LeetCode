
Item = collections.namedtuple('Item', 'phrase,first,last,count')

class Solution:

    def split(self, phrase):
        words = phrase.split(' ')
        return Item(phrase, words[0], words[-1], len(words))

    def concat(self, i, j):
        return i.phrase if j.count == 1 else i.phrase + " " + j.phrase[len(j.first) + 1:]

    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        items = list(map(self.split, phrases))
        n = len(items)
        ans = [
            self.concat(items[i], items[j])
            for i in range(n)
            for j in range(n)
            if i != j and items[i].last == items[j].first
        ]
        return sorted(set(ans))

