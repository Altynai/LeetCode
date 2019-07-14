class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        index = {value: i for i, value in enumerate(arr2)}
        items = [
            # in arr2 ?
            # index in arr2
            # index in arr1
            # value itself
            (-int(value in index), index.get(value, -1), index, value)
            for i, value in enumerate(arr1)
        ]
        items.sort()
        return [item[3] for item in items]

