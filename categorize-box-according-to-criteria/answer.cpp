const int N = 1e4;
const int M = 1e9;

class Solution {
public:
  string categorizeBox(int length, int width, int height, int mass) {
    bool bulky = (length >= N or width >= N or height >= N or mass >= N);
    bulky = (bulky or 1LL * length * width * height >= M);

    bool heavy = (mass >= 100);

    if (bulky and heavy)
      return "Both";
    else if (bulky and !heavy)
      return "Bulky";
    else if (!bulky and heavy)
      return "Heavy";
    return "Neither";
  }
};
