class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));
        priority_queue<vector<int>> pq;

        int start = health - grid[0][0];
        if (start <= 0) return false;

        pq.push({start, 0, 0});
        best[0][0] = start;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int h = cur[0], x = cur[1], y = cur[2];

            if (x == m - 1 && y == n - 1) return true;
            if (h < best[x][y]) continue;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nh = h - grid[nx][ny];
                    if (nh > 0 && nh > best[nx][ny]) {
                        best[nx][ny] = nh;
                        pq.push({nh, nx, ny});
                    }
                }
            }
        }

        return false;
    }
};