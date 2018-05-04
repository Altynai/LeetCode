class Solution(object):
    def check(self, a, b):
        # age[B] <= 0.5 * age[A] + 7
        # age[B] > age[A]
        # age[B] > 100 && age[A] < 100
        if float(b) <= float(a) * 0.5 + 7:
            return False
        if b > a:
            return False
        if b > 100 and a < 100:
            return False
        return True

    def numFriendRequests(self, ages):
        counter = collections.defaultdict(int)
        for age in ages:
            counter[age] += 1
        ans = 0
        items = [(a, n) for a, n in counter.iteritems()]
        for i, (a, n) in enumerate(items):
            if self.check(a, a):
                ans += n * (n - 1)
            for j, (b, m) in enumerate(items):
                if i == j:
                    continue
                if self.check(a, b):
                    ans += n * m
        return ans
