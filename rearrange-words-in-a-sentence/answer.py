class Solution:
    def arrangeWords(self, text: str) -> str:
        words = list([s.lower(), i] for i, s in enumerate(text.split(" ")))
        words.sort(key=lambda x: (len(x[0]), x[1]))
        return " ".join(w[0] for w in words).capitalize()

