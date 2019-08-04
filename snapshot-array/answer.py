class SnapshotArray:

    def __init__(self, length: int):
        self.map = collections.defaultdict(list)
        self.buf = {}
        self.snap_id = 0

    def set(self, index: int, val: int) -> None:
        self.buf[index] = val

    def snap(self) -> int:
        for index, val in self.buf.items():
            self.map[index].append((self.snap_id, val))
        self.snap_id += 1
        self.buf = {}
        return self.snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        if index not in self.map:
            return 0
        items = self.map.get(index, [])
        l, r, i = 0, len(items) - 1, -1
        while l <= r:
            mid = (l + r) >> 1
            version, value = items[mid]
            if version <= snap_id:
                l, i = mid + 1, mid
            else:
                r = mid - 1
        return 0 if i == -1 else items[i][1]

# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
