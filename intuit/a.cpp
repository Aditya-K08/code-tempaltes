#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int getNumWays(int n, vector<int> edge_from, vector<int> edge_to) {
        const long long MOD = 1000000007LL;

        vector<int> primes;
        vector<bool> isPrime(201, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 200; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 200; j += i) isPrime[j] = false;
            }
        }
        for (int i = 2; i <= 100; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }

        int m = primes.size();
        vector<vector<int>> ok(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                ok[i][j] = !isPrime[primes[i] + primes[j]];
            }
        }

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u = edge_from[i], v = edge_to[i];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(n + 1, -1), order;
        order.reserve(n);
        stack<int> st;
        st.push(1);
        parent[1] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            order.push_back(u);
            for (int v : g[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                st.push(v);
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(m, 1));

        for (int idx = n - 1; idx >= 0; --idx) {
            int u = order[idx];
            for (int v : g[u]) {
                if (v == parent[u]) continue;
                vector<long long> sum(m, 0);
                for (int c = 0; c < m; ++c) {
                    long long ways = 0;
                    for (int nc = 0; nc < m; ++nc) {
                        if (ok[c][nc]) {
                            ways += dp[v][nc];
                            if (ways >= MOD) ways -= MOD;
                        }
                    }
                    sum[c] = ways;
                }
                for (int c = 0; c < m; ++c) {
                    dp[u][c] = dp[u][c] * sum[c] % MOD;
                }
            }
        }

        long long ans = 0;
        for (int c = 0; c < m; ++c) {
            ans += dp[1][c];
            if (ans >= MOD) ans -= MOD;
        }
        return (int)ans;
    }
};

int main() {
    Solution sol;

    {
        int n = 2;
        vector<int> edge_from = {1};
        vector<int> edge_to = {2};
        cout << sol.getNumWays(n, edge_from, edge_to) << '\n';
    }

    {
        int n = 3;
        vector<int> edge_from = {1, 1};
        vector<int> edge_to = {2, 3};
        cout << sol.getNumWays(n, edge_from, edge_to) << '\n';
    }

    {
        int n = 4;
        vector<int> edge_from = {1, 2, 3};
        vector<int> edge_to = {2, 3, 4};
        cout << sol.getNumWays(n, edge_from, edge_to) << '\n';
    }

    return 0;
}