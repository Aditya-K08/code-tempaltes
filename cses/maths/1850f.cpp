#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> freq(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n) freq[x]++;  
    }

    vector<int> cnt(n + 1, 0);

    for (int x = 1; x <= n; x++) {
        if (freq[x] == 0) continue;
        for (int j = x; j <= n; j += x) {
            cnt[j] += freq[x];
        }
    }

    int maxi = 0;
    for (int j = 1; j <= n; j++) {
        maxi = max(maxi, cnt[j]);
    }

    cout << maxi << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}