class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        
        n = len(customers)
        wait = when = 0

        for arr, tm in customers:
            if when < arr:
                when = arr
            when += tm
            wait += when - arr
        
        return wait / n

