class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.n = n
        self.m = 0
        self.d = 1.0 - discount / 100.0
        self.p = dict(zip(products, prices))

    def getBill(self, product: List[int], amount: List[int]) -> float:
        total = sum(j * self.p[i] for i, j in zip(product, amount))
        self.m = (self.m + 1) % self.n
        return total * self.d if self.m == 0 else total


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
