class Logger {
public:
    map<string, int> lastPrintedTime;

    /** Initialize your data structure here. */
    Logger() {
        lastPrintedTime.clear();
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = lastPrintedTime.find(message);
        if (it == lastPrintedTime.end()) {
            lastPrintedTime[message] = timestamp;
            return true;
        } else {
            int seconds = timestamp - it->second;
            if (seconds >= 10) {
                lastPrintedTime[message] = timestamp;
                return true;
            } else {
                return false;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */