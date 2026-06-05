class Solution {
public:
    struct Node {
        long long ways;
        long long waviness;
    };

    string s;
    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node dfs(int pos, int tight, int started, int prev2, int prev1) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][started][prev2][prev1]) {
            return dp[pos][tight][started][prev2][prev1];
        }

        vis[pos][tight][started][prev2][prev1] = true;

        Node ans = {0, 0};

        int limit = tight ? (s[pos] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            // Still leading zeros
            if (!started && d == 0) {
                Node child = dfs(pos + 1, ntight, 0, 10, 10);

                ans.ways += child.ways;
                ans.waviness += child.waviness;
                continue;
            }

            int extra = 0;

            if (started) {
                if (prev2 != 10 && prev1 != 10) {
                    int a = prev2;
                    int b = prev1;
                    int c = d;

                    if ((b > a && b > c) ||
                        (b < a && b < c)) {
                        extra = 1;
                    }
                }

                Node child = dfs(pos + 1, ntight, 1, prev1, d);

                ans.ways += child.ways;
                ans.waviness += child.waviness +
                                1LL * extra * child.ways;
            } else {
                // First non-zero digit
                Node child = dfs(pos + 1, ntight, 1, 10, d);

                ans.ways += child.ways;
                ans.waviness += child.waviness;
            }
        }

        return dp[pos][tight][started][prev2][prev1] = ans;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 10, 10).waviness;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};