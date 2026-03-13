#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        string S;
        cin >> S;
        int n = (int)S.size();

        int Q;
        cin >> Q;

        vector<pair<int, int>> queries(Q);
        vector<int> deleted(n, 0);

        for (int i = 0; i < Q; i++) {
            int type, idx;
            cin >> type >> idx;
            queries[i] = {type, idx};
            if (type == 2) deleted[idx] = 1;
        }

        DSU dsu(n);
        vector<int> active(n, 0);

        for (int i = 0; i < n; i++) {
            if (!deleted[i]) active[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            if (active[i] && active[i - 1] && S[i] == S[i - 1]) {
                dsu.unite(i, i - 1);
            }
        }

        vector<int> answers;

        for (int qi = Q - 1; qi >= 0; qi--) {
            int type = queries[qi].first;
            int idx = queries[qi].second;

            if (type == 1) {
                answers.push_back(dsu.size(idx));
            } else {
                active[idx] = 1;
                if (idx - 1 >= 0 && active[idx - 1] && S[idx] == S[idx - 1]) {
                    dsu.unite(idx, idx - 1);
                }
                if (idx + 1 < n && active[idx + 1] && S[idx] == S[idx + 1]) {
                    dsu.unite(idx, idx + 1);
                }
            }
        }

        reverse(answers.begin(), answers.end());

        cout << "Case " << tc << ":\n";
        for (int x : answers) {
            cout << x << '\n';
        }
    }

    return 0;
}