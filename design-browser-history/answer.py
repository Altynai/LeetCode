class BrowserHistory:

    def __init__(self, homepage: str):
        self.urls = [homepage]
        self.n = 1

    def visit(self, url: str) -> None:
        if self.n == len(self.urls):
            self.urls.append(url)
        else:
            self.urls[self.n] = url
        self.n += 1

        while len(self.urls) > self.n:
            self.urls.pop()

    def back(self, steps: int) -> str:
        self.n = max(1, self.n - steps)
        return self.urls[self.n - 1]

    def forward(self, steps: int) -> str:
        self.n = min(len(self.urls), self.n + steps)
        return self.urls[self.n - 1]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
