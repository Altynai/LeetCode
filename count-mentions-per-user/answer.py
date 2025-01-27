class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        events = [(int(e[1]), e[0], e[2]) for e in events]
        events.sort(key=lambda e: (e[0], e[1] != "OFFLINE"))

        onlineTimes = {i: 0 for i in range(numberOfUsers)}
        mentionedAll = 0

        mentions = [0 for i in range(numberOfUsers)]
        
        for (ts, message, data) in events:
            if message == "OFFLINE":
                uid = int(data)
                onlineTimes[uid] = ts + 60
            else:
                if data == "ALL":
                    mentionedAll += 1
                elif data == "HERE":
                    uids = [uid for (uid, t) in onlineTimes.items() if t <= ts]
                    for uid in uids:
                        mentions[uid] += 1
                else:
                    uids = [int(s[2:]) for s in data.split(" ")]
                    for uid in uids:
                        mentions[uid] += 1

        return [m + mentionedAll for m in mentions]
        
