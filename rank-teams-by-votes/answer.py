from collections import defaultdict, Counter
from functools import cmp_to_key

class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        n = len(votes)
        if n == 1:
            return votes[0]

        p = defaultdict(Counter)
        teams = set()
        for vote in votes:
            for i, team in enumerate(vote):
                teams.add(team)
                p[team][i] += 1

        ans = list(teams)
        def _cmp(a, b):
            pa, pb = p[a], p[b]
            for j in range(n):
                na, nb = pa.get(j, 0), pb.get(j, 0)
                if na != nb:
                    return -1 if na > nb else 1
            return -1 if a < b else 1

        ans.sort(key=cmp_to_key(_cmp))
        return ''.join(ans)

