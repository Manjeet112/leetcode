class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        const long long INF = 1e18;
         unordered_map<string,int> id;
        int idx = 0;

        auto getId = [&](const string& s){
            if(!id.count(s)) id[s] = idx++;
            return id[s];
        };

        for(auto &s: original) getId(s);
        for(auto &s: changed)  getId(s);

        int V = idx;
         vector<vector<pair<int,int>>> g(V);

        for(int i=0;i<original.size();i++){
            g[id[original[i]]].push_back({id[changed[i]], cost[i]});
        }
         vector<vector<long long>> dist(V, vector<long long>(V, INF));

        for(int s=0;s<V;s++){
            priority_queue<pair<long long,int>,
                           vector<pair<long long,int>>,
                           greater<>> pq;
                           dist[s][s] = 0;
            pq.push({0,s});

            while(!pq.empty()){
                auto [d,u] = pq.top(); pq.pop();
                if(d > dist[s][u]) continue;

                for(auto &[v,w] : g[u]){
                    if(dist[s][v] > d + w){
                        dist[s][v] = d + w;
                        pq.push({dist[s][v], v});
                    }
                }
            }
        }
        unordered_set<int> lens;
        for(auto &s: original) lens.insert(s.size());
        vector<long long> dp(n+1, INF);
        dp[0] = 0;

        for(int i=0;i<n;i++){
            if(dp[i] == INF) continue;

            // char equal → free move
            if(source[i] == target[i])
                dp[i+1] = min(dp[i+1], dp[i]);

            // only valid lengths
            for(int len : lens){
                if(i + len > n) continue;

                string_view s1(source.data()+i, len);
                string_view s2(target.data()+i, len);
                 if(id.count(string(s1)) && id.count(string(s2))){
                    long long c = dist[id[string(s1)]][id[string(s2)]];
                    if(c != INF)
                        dp[i+len] = min(dp[i+len], dp[i] + c);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};