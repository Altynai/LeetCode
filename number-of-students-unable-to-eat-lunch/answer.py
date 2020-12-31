class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        
        students = collections.deque(students)
        sandwiches = collections.deque(sandwiches)

        while sandwiches:
            top = sandwiches[0]
            if top not in students:
                break
            while students[0] != top:
                students.rotate(-1)
            
            students.popleft()
            sandwiches.popleft()

        return len(students)

