#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rnk;

    DSU(int n) {
        parent.resize(n + 1);
        rnk.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> edges(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    vector<int> removed(m + 1, 0);

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
        removed[queries[i]] = 1;
    }

    DSU dsu(n);
    int comp = n;

    for (int i = 1; i <= m; i++) {
        if (!removed[i]) {
            if (dsu.unite(edges[i].first, edges[i].second)) {
                comp--;
            }
        }
    }

    vector<int> ans;
    reverse(queries.begin(), queries.end());

    for (int id : queries) {
        ans.push_back(comp);
        int u = edges[id].first;
        int v = edges[id].second;
        if (dsu.unite(u, v)) comp--;
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}