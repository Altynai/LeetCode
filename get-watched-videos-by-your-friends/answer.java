import java.util.Arrays;
import java.util.List;
import java.util.Map.Entry;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
  public List<String> watchedVideosByFriends(
      List<List<String>> watchedVideos, int[][] friends, int id, int level) {
    final int n = watchedVideos.size();
    int[][] mat = new int[n][n];
    for (int i = 0; i < n; i++) Arrays.fill(mat[i], -1);
    for (int i = 0; i < n; i++) {
      mat[i][i] = 0;
      for (int j : friends[i]) {
        mat[i][j] = 1;
        mat[j][i] = 1;
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (mat[i][k] != -1 && mat[k][j] != -1) {
            int val = mat[i][k] + mat[k][j];
            if (mat[i][j] == -1 || val < mat[i][j]) mat[i][j] = val;
          }
        }
      }
    }

    return IntStream.range(0, n).filter(i -> mat[id][i] == level).boxed().map(watchedVideos::get)
        .flatMap(List::stream)
        .collect(Collectors.groupingBy(String::toString, Collectors.counting())).entrySet().stream()
        .sorted(
            (lh, rh) ->
                lh.getValue().equals(rh.getValue())
                    ? lh.getKey().compareTo(rh.getKey())
                    : lh.getValue().compareTo(rh.getValue()))
        .map(Entry::getKey)
        .collect(Collectors.toList());
  }
}

