from collections import defaultdict

class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        mp = defaultdict(lambda: defaultdict(int))
        foods = set()
        tables = set()
        for (name, table, food) in orders:
            foods.add(food)
            tables.add(int(table))
            mp[int(table)][food] += 1
        
        ans = []
        foods = sorted(foods)
        tables = sorted(tables)
        
        ans.append(["Table"] + foods)
        for table in tables:
            counter = mp[table]
            ans.append([str(table)] + [str(counter.get(food, 0)) for food in foods])
        return ans

