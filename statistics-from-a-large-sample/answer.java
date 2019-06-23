class Solution {
    private double findMin(int[] count) {
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0)
                return i;
        }
        return -1;
    }

    private double findMax(int[] count) {
        for (int i = count.length - 1; i >= 0; i--) {
            if (count[i] > 0)
                return i;
        }
        return -1;
    }

    private double findSum(int[] count) {
        double sum = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0)
                sum += (double) count[i] * i;
        }
        return sum;
    }

    private int findTotal(int[] count) {
        int total = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0)
                total += count[i];
        }
        return total;
    }

    private int get(int[] count, int offset) {
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0) {
                if (count[i] >= offset)
                    return i;
                else
                    offset -= count[i];
            }
        }
        return -1;
    }

    private double findMode(int[] count) {
        int index = -1;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0)
                index = (index == -1 || count[i] > count[index]) ? i : index;
        }
        return index;
    }

    public double[] sampleStats(int[] count) {
        int total = findTotal(count);
        double mean = findSum(count) / total;
        double median = get(count, total / 2 + 1);
        if (total % 2 == 0)
            median = ((double) get(count, total / 2) + get(count, total / 2 + 1)) / 2.0;
        return new double[]{findMin(count), findMax(count), mean, median, findMode(count)};
    }
}
