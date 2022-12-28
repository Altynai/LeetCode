from collections import defaultdict


class Solution:
    def topStudents(
        self,
        positive_feedback: List[str],
        negative_feedback: List[str],
        report: List[str],
        student_id: List[int],
        k: int,
    ) -> List[int]:
        pf = set(positive_feedback)
        nf = set(negative_feedback)

        score = defaultdict(int)
        n = len(student_id)

        for i in range(n):
            sid = student_id[i]
            s = 0
            for word in report[i].split():
                if word in pf:
                    s += 3
                if word in nf:
                    s -= 1
            score[sid] += s

        students = [(-value, sid) for sid, value in score.items()]
        students.sort()
        sids = [sid for (_, sid) in students]
        return sids[:k]
