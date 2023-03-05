class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return 0;
        }

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            if (graph.find(arr[i]) != graph.end()) {
                graph[arr[i]].push_back(i);
            } else {
                graph[arr[i]] = {i};
            }
        }

        vector<int> curs = {0};
        unordered_set<int> visited = {0};
        int step = 0;

        while (!curs.empty()) {
            vector<int> nex;

            for (int node : curs) {
                if (node == n-1) {
                    return step;
                }

                for (int child : graph[arr[node]]) {
                    if (visited.find(child) == visited.end()) {
                        visited.insert(child);
                        nex.push_back(child);
                    }
                }

                graph[arr[node]].clear();

                if (node-1 >= 0 && visited.find(node-1) == visited.end()) {
                    visited.insert(node-1);
                    nex.push_back(node-1);
                }
                if (node+1 < n && visited.find(node+1) == visited.end()) {
                    visited.insert(node+1);
                    nex.push_back(node+1);
                }
            }

            curs = nex;
            step++;
        }

        return -1;
    }
};
