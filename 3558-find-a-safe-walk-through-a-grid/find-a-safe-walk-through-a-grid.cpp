class Solution {
public:
    int m, n;
    vector<vector<int>> best;

    bool dfs(int i, int j, vector<vector<int>>& grid, int health,
             vector<vector<bool>>& visited) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (visited[i][j])
            return false;

        if (grid[i][j] == 1)
            health--;

        if (health <= 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return true;

        // Prune if we've already reached this cell with
        // at least this much remaining health.
        if (best[i][j] >= health)
            return false;

        best[i][j] = health;

        visited[i][j] = true;

        bool ans = dfs(i + 1, j, grid, health, visited) ||
                   dfs(i - 1, j, grid, health, visited) ||
                   dfs(i, j + 1, grid, health, visited) ||
                   dfs(i, j - 1, grid, health, visited);

        visited[i][j] = false;

        return ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        m = grid.size();
        n = grid[0].size();

        best.assign(m, vector<int>(n, -1));

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(0, 0, grid, health, visited);
    }
};