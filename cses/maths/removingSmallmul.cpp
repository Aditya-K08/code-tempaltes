#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    char c;
    string s;
    cin >> c >> s;

    bool allSame = true;
    for (char ch : s) {
        if (ch != c) {
            allSame = false;
            break;
        }
    }

    if (allSame) {
        cout << 0 << '\n';
        return;
    }

    for (int x = 1; x <= n; x++) {
        bool ok = true;
        for (int j = x; j <= n; j += x) {
            if (s[j - 1] != c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << 1 << '\n';
            cout << x << '\n';
            return;
        }
    }

    cout << 2 << '\n';
    cout << n << " " << n - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}