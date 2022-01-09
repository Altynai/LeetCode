class Solution:
    def capitalizeTitle(self, title: str) -> str:
        return " ".join(s.lower() if len(s) <= 2 else s.title() for s in title.split())
