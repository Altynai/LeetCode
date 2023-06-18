class Solution {
public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int liter = 0;
    while (mainTank >= 5) {
      liter += 5;
      mainTank -= 5;
      if (additionalTank > 0)
        mainTank++, additionalTank--;
    }
    liter += mainTank;
    return liter * 10;
  }
};
