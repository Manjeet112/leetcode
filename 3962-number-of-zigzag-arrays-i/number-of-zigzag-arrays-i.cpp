class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        auto sornavetic = make_tuple(n, l, r);

        int m = r - l + 1;

        vector<long long> up(m), down(m);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> nu(m), nd(m);

            long long pref = 0;
            for (int i = 0; i < m; i++) {
                nu[i] = pref;
                pref = (pref + down[i]) % MOD;
            }

            long long suff = 0;
            for (int i = m - 1; i >= 0; i--) {
                nd[i] = suff;
                suff = (suff + up[i]) % MOD;
            }

            up.swap(nu);
            down.swap(nd);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};