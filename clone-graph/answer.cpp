
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    map<int, UndirectedGraphNode *> label_node_map;

    void updateLableNodeMap(UndirectedGraphNode *node) {
        label_node_map.clear();
        queue<UndirectedGraphNode *> q;
        q.push(node);

        while (!q.empty()) {
            node = q.front();
            q.pop();
            map<int, UndirectedGraphNode *>::iterator it = label_node_map.find(node->label);
            if (it == label_node_map.end()) {
                label_node_map[node->label] = new UndirectedGraphNode(node->label);
                for (int i = 0; i < (int)node->neighbors.size(); i++) {
                    int next_label = (node->neighbors[i])->label;
                    it = label_node_map.find(next_label);
                    if (it == label_node_map.end())
                        q.push(node->neighbors[i]);
                }
            }
        }
    }

    UndirectedGraphNode *cloneTheGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *old_node = node, *new_node = NULL;
        queue<UndirectedGraphNode *> q;
        q.push(old_node);
        set<int> visited;
        int start_label = old_node->label;
        visited.insert(start_label);

        while (!q.empty()) {
            old_node = q.front();
            q.pop();
            new_node = label_node_map[old_node->label];

            for (int i = 0; i < (int)old_node->neighbors.size(); i++) {
                int next_label = (old_node->neighbors[i])->label;
                new_node->neighbors.push_back(label_node_map[next_label]);
                if (visited.find(next_label) == visited.end()) {
                    q.push(old_node->neighbors[i]);
                    visited.insert(next_label);
                }
            }
        }
        return label_node_map[start_label];
    }

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        updateLableNodeMap(node);
        return cloneTheGraph(node);
    }
};