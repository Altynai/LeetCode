class Solution:
    def reformatDate(self, date: str) -> str:
        a, b, c = date.split()
        m = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        b = m.index(b) + 1
        a = int(a[:-2])
        return "{}-{:02d}-{:02d}".format(c, b, a)

