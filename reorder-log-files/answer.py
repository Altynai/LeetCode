class Solution:

    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        Log = collections.namedtuple('Log', 'ident,idx,suffix,type')

        def convert(idx, log):
            parts = log.split(' ')
            _type = 1 if parts[1].isdigit() else 0
            return Log(parts[0], idx, ' '.join(parts[1:]), _type)

        logs = [convert(idx, log) for idx, log in enumerate(logs)]
        
        def cmp(x, y):
            if x.type != y.type:
                return -1 if x.type < y.type else 1
            elif x.type == 0:
                return -1 if x.suffix < y.suffix else 1
            elif x.type == 1:
                return -1 if x.idx < y.idx else 1
            else:
                return 0
        
        logs.sort(cmp=cmp)
        return [' '.join([log.ident, log.suffix]) for log in logs]

