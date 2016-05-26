#define NIL -1

bool compare(const pair<string, string>& lh, const pair<string, string>& rh) {
    if (lh.first != rh.first)
        return lh.first < rh.first;
    return lh.second > rh.second;
}

struct Edge {
    int v, nxt;
    bool visited;
};

class Solution {
private:
    int n, m;
    map<string, int> name2id;
    map<int, string> id2name;
    vector<Edge> edges;
    vector<int> head;

    int getAirportID(string name) {
        map<string, int>::iterator it = name2id.find(name);
        if (it == name2id.end()) {
            name2id[name] = n;
            id2name[n] = name;
            return n++;
        } else
            return it->second;
    }

    string getAirportName(int id) {
        map<int, string>::iterator it = id2name.find(id);
        if (it == id2name.end())
            return "";
        else
            return it->second;
    }

    void addEdge(int u, int v) {
        edges[m].v = v;
        edges[m].nxt = head[u];
        head[u] = m++;
    }

    void buildDAG(vector<pair<string, string> >& tickets) {
        sort(tickets.begin(), tickets.end(), compare);
        for (int i = 0; i < (int)tickets.size(); ++i) {
            pair<string, string>& ticket = tickets[i];
            int u = getAirportID(ticket.first), v = getAirportID(ticket.second);
            addEdge(u, v);
        }
    }

    void init(vector<pair<string, string> >& tickets) {
        n = m = 0;
        if (tickets.size() == 0)
            return;
        set<string> names;
        for (int i = 0; i < tickets.size(); ++i) {
            pair<string, string>& ticket = tickets[i];
            names.insert(ticket.first);
            names.insert(ticket.second);
        }
        edges = vector<Edge>(tickets.size());
        head = vector<int>(names.size(), NIL);
        buildDAG(tickets);
    }

    bool dfs(int travel, int u, vector<int>& path) {
        if (travel == m)
            return true;
        for (int p = head[u]; p != NIL; p = edges[p].nxt) {
            Edge& e = edges[p];
            if (e.visited)
                continue;
            path[travel + 1] = e.v;
            e.visited = true;
            if (dfs(travel + 1, e.v, path))
                return true;
            else
                e.visited = false;
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        init(tickets);
        if (n == 0)
            return vector<string>();
        vector<int> path(m + 1);
        int start = getAirportID("JFK");
        path[0] = start;
        dfs(0, start, path);
        vector<string> answer(m + 1);
        for (int i = 0; i < m + 1; ++i)
            answer[i] = getAirportName(path[i]);
        return answer;
    }
};