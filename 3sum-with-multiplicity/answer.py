class Solution:

    MOD = 1000000000 + 7
    
    def add(self, a, b):
        return (a + b) % self.MOD

    def threeSumMulti(self, A, target):
        """
        :type A: List[int]
        :type target: int
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        for a in A:
            cnt[a] += 1
        nums = list(cnt.keys())
        nums.sort()
        
        s = 0
        n = len(nums)

        # 3
        if (target % 3 == 0):
            times = cnt.get(target // 3, 0)
            if times >= 3:
                s = self.add(s, times * (times - 1) * (times - 2) // 6)
        
        # (1 + 2) (2 + 1)
        for first in (True, False):
            i = 0
            j = n - 1
            while i < j:
                total = (nums[i] + 2 * nums[j]) if first else (2 * nums[i] + nums[j])
                if total == target:
                    a = cnt[nums[i]]
                    b = cnt[nums[j]]
                    c = b if first else a
                    d = a * b * (b - 1) // 2 if first else a * (a - 1) * b // 2
                    if (c >= 2):
                        s = self.add(s, d)
                    i += 1
                elif total < target:
                    i += 1
                else:
                    j -= 1
        
        # 1 + 1 + 1
        for j in range(n):
            for i in range(j - 1):
                k = target - nums[i] - nums[j]
                i2 = i + 1
                j2 = j - 1
                where = -1
                while i2 <= j2:
                    mid = (i2 + j2) >> 1
                    if nums[mid] == k:
                        where = mid
                        break
                    elif nums[mid] < k:
                        i2 = mid + 1
                    else:
                        j2 = mid - 1

                if where != -1:
                    s = self.add(s, cnt[nums[i]] * cnt[nums[where]] * cnt[nums[j]])

        return s

