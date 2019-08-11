class Solution:
    def dayOfYear(self, date: str) -> int:
        import datetime
        now = datetime.datetime.strptime(date, "%Y-%m-%d").date()
        return (now - datetime.date(now.year, 1, 1)).days + 1

