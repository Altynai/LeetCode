"""
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution(object):
    def dfs(self, employee):
        if employee is None:
            return 0
        iterator = (
            self.dfs(self.id2employee.get(id))
            for id in employee.subordinates
        )
        return sum(iterator, employee.importance)

    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        self.id2employee = {e.id: e for e in employees}
        e = self.id2employee.get(id)
        return self.dfs(e)

