class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            vector<int> comp;
            int edgeCount = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                comp.push_back(u);
                edgeCount += adj[u].size();

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            int nodes = comp.size();
            edgeCount /= 2;

            if (edgeCount == nodes * (nodes - 1) / 2)
                ans++;
        }

        return ans;
    }
};