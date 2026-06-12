
        class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int LOG = 17;

    vector<vector<int>> parent;
    vector<int> depth;
    vector<vector<int>> adj;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void dfs(int u, int p) {
        parent[0][u] = p;

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[k][u] != -1 &&
                depth[parent[k][u]] >= depth[v]) {
                u = parent[k][u];
            }
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[k][u] != -1 &&
                parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        return parent[0][u];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        adj.resize(n + 1);
        depth.assign(n + 1, 0);
        parent.assign(LOG, vector<int>(n + 1, -1));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        for (int k = 1; k < LOG; k++) {
            for (int v = 1; v <= n; v++) {
                if (parent[k - 1][v] != -1) {
                    parent[k][v] =
                        parent[k - 1][parent[k - 1][v]];
                }
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int a = lca(u, v);

            int d = depth[u] + depth[v] - 2 * depth[a];

            ans.push_back(modPow(2, d - 1));
        }

        return ans;
    }
};
