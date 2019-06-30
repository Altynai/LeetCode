class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int n = (int) Math.sqrt((double) candies);
        while (n * (n + 1) > candies * 2)
            n--;

        int turns = n / num_people;
        int[] ans = new int[num_people];
        if (turns > 0) {
            for (int i = 1; i <= num_people; i++) {
                int first = i, last = i + (turns - 1) * num_people;
                ans[i - 1] = (first + last) * turns / 2;
                candies -= ans[i - 1];
            }
        }
        int i = 1, expected = num_people * turns + 1;
        while (candies > 0) {
            ans[i - 1] += Math.min(candies, expected);
            candies -= Math.min(candies, expected);
            i = (i == num_people) ? 1 : i + 1;
            expected++;
        }
        return ans;
    }
}
