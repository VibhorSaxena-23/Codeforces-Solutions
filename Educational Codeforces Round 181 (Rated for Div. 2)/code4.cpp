#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;


ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

ll modinv(ll a, ll m) {
    ll x, y;
    egcd(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> seg(m + 2);
    ll baseProb = 1;

    for (int i = 0; i < n; i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        ll p_mod = (ll)p * modinv(q, MOD) % MOD;
        // Compute (q - p)/q modulo MOD
        ll q_minus_p_mod = ((ll)(q - p) * modinv(q, MOD)) % MOD;

        // w = (p/q) / ((q-p)/q) = p / (q - p) mod MOD
        ll w = p_mod * modinv(q_minus_p_mod, MOD) % MOD;

        seg[r].push_back({l, w});
        baseProb = baseProb * q_minus_p_mod % MOD;
    }

    vector<ll> dp(m + 1);
    dp[0] = 1;

    for (int r = 1; r <= m; r++) {
        ll sum = 0;
        for (auto &pr : seg[r]) {
            int l = pr.first;
            ll w = pr.second;
            sum = (sum + dp[l - 1] * w) % MOD;
        }
        dp[r] = sum;
    }

    ll ans = baseProb * dp[m] % MOD;
    cout << ans << "\n";

    return 0;
}
