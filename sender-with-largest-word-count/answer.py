import collections


class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        cnt = collections.defaultdict(int)
        for sender, message in zip(senders, messages):
            cnt[sender] += len(message.split(" "))

        name = None
        for sender, times in cnt.items():
            if (
                name is None
                or times > cnt[name]
                or (times == cnt[name] and sender > name)
            ):
                name = sender

        return name
