class AuthenticationManager {
private:
    int ttl;
    map<string, int> expire;

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive; 
        expire.clear();
    }
    
    void generate(string tokenId, int currentTime) {
        expire[tokenId] = ttl + currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        auto it = expire.find(tokenId);
        if (it != expire.end() && currentTime < it->second) {
            expire[tokenId] = ttl + currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto&[k,v]: expire) {
            if (currentTime < v)
                ans++;
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
