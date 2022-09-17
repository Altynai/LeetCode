const int M[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
public:
  int get(string s) {
    int day = 0;
    int x = (s[0] - '0') * 10 + (s[1] - '0');
    int y = (s[3] - '0') * 10 + (s[4] - '0');
    for (int i = 1; i < x; i++)
      day += M[i - 1];
    return day + y;
  }

  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    int ax = get(arriveAlice), ay = get(leaveAlice);
    int bx = get(arriveBob), by = get(leaveBob);

    int mi = max(ax, bx);
    int ma = min(ay, by);

    if (mi > ma)
      return 0;
    return ma - mi + 1;
  }
};
