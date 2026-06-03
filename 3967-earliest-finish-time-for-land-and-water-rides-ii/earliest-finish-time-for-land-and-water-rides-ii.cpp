class Solution {
public:
    long long solve(vector<int>& Astart, vector<int>& Adur,
                    vector<int>& Bstart, vector<int>& Bdur) {

        int n = Astart.size();
        int m = Bstart.size();

        vector<pair<long long,long long>> B(m);

        for (int i = 0; i < m; i++)
            B[i] = {(long long)Bstart[i], (long long)Bdur[i]};

        sort(B.begin(), B.end());

        vector<long long> starts(m);
        vector<long long> prefMinDur(m);
        vector<long long> suffMinFinish(m + 1, LLONG_MAX);

        for (int i = 0; i < m; i++)
            starts[i] = B[i].first;

        prefMinDur[0] = B[0].second;

        for (int i = 1; i < m; i++)
            prefMinDur[i] = min(prefMinDur[i - 1], B[i].second);

        for (int i = m - 1; i >= 0; i--)
            suffMinFinish[i] =
                min(suffMinFinish[i + 1],
                    B[i].first + B[i].second);

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {

            long long finishA =
                (long long)Astart[i] + Adur[i];

            int pos =
                upper_bound(starts.begin(),
                            starts.end(),
                            finishA)
                - starts.begin();

            if (pos > 0)
                ans = min(ans,
                          finishA + prefMinDur[pos - 1]);

            if (pos < m)
                ans = min(ans,
                          suffMinFinish[pos]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans1 =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        long long ans2 =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return (int)min(ans1, ans2);
    }
};