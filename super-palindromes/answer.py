class Solution(object):
    def __init__(self):
        # L = 1
        # R = 10 ** 18

        # def palindrome(x):
        #     return x[::-1] == x

        # def ok(x):
        #     k = int(x) ** 2
        #     return L <= k <= R and palindrome(str(k))

        # self.nums = []
        # for i in xrange(1, 100000):
        #     s = str(i)
        #     t = s + s[-2::-1]
        #     if ok(t):
        #         self.nums.append(int(t) ** 2)
        #     t = s + s[::-1]
        #     if ok(t):
        #         self.nums.append(int(t) ** 2)
        self.nums = [1, 121, 4, 484, 9, 10201, 1002001, 12321, 1234321, 14641, 40804, 4008004, 44944, 100020001, 10000200001, 102030201, 10221412201, 104060401, 121242121, 12102420121, 123454321, 12345654321, 125686521, 400080004, 40000800004, 404090404, 1000002000001, 100000020000001, 1002003002001, 100220141022001, 1004006004001, 1020304030201, 102012040210201, 1022325232201, 102234363432201, 1024348434201, 1210024200121, 121000242000121, 1212225222121, 121242363242121, 1214428244121, 1232346432321, 123212464212321, 1234567654321, 123456787654321, 4000008000004, 400000080000004, 4004009004004, 10000000200000001, 10002000300020001, 10004000600040001, 10020210401202001, 10022212521222001, 10024214841242001, 10201020402010201, 10203040504030201, 10205060806050201, 10221432623412201, 10223454745432201, 12100002420000121, 12102202520220121, 12104402820440121, 12122232623222121, 12124434743442121, 12321024642012321, 12323244744232321, 12343456865434321, 12345678987654321, 40000000800000004, 40004000900040004]

    def superpalindromesInRange(self, L, R):
        """
        :type L: str
        :type R: str
        :rtype: int
        """
        L, R = int(L), int(R)
        return sum(1 for num in self.nums if L <= num <= R)

