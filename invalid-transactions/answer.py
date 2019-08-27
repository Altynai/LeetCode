class Solution:

    def convert(self, transaction):
        name, time, amount, city = transaction.split(',')
        return (name, int(time), int(amount), city)
    
    def convert2(self, transaction):
        return ','.join(map(str, transaction))

    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        transactions = list(map(self.convert, transactions))
        transactions.sort(key=lambda x: x[1])
        last = collections.defaultdict(collections.deque)
        invalid = set()
        
        for i, transaction in enumerate(transactions):
            name, time, amount, city = transaction
            if amount > 1000:
                invalid.add(i)
            dq = last[name]
            while dq and time - dq[0][0] > 60:
                dq.popleft()
            for _, city2, j in dq:
                if city != city2:
                    invalid.add(i)
                    invalid.add(j)
            last[name].append((time, city, i))

        return [self.convert2(transactions[i]) for i in invalid]

