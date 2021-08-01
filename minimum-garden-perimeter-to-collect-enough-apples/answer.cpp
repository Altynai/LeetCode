class Solution {
public:
  long long minimumPerimeter(long long neededApples) {
    // (-i, i) .... (0, i) .... (i, i)
    // (-i, 0) .... (0, 0) .... (i, 0)
    // (-i, -i) ....(0, -i).... (i, -i)
    // each edge = i(2i + 1) + i(i + 1) = 3i^2 + 2i
    // f[i] = f[i-1] + 12i^2
    int i = 1;
    long long have = 0;
    while (have < neededApples) {
      have += 12LL * i * i;
      i++;
    }
    return 8LL * (i - 1);
  }
};
