#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int bad_primes[] = {2, 3, 5, 7};

bool will_overflow(ll a, ll b, ll x) {
    if (a == 0 || b == 0) return false;
    return a > x / b;
}

ll count_bad(ll x) {
    ll count = 0;
    int n = 4;

    for (int mask = 1; mask < (1 << n); ++mask) {
        ll prod = 1;
        bool overflow = false;

        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                if (will_overflow(prod, bad_primes[i], x)) {
                    overflow = true;
                    break;
                }
                prod *= bad_primes[i];
            }
        }

        if (overflow || prod > x) continue;

        ll contrib = x / prod;
        int bits = __builtin_popcount(mask);

        if (bits % 2 == 1)
            count += contrib;
        else
            count -= contrib;
    }

    return count;
}

ll good_count(ll l, ll r) {
    return (r - l + 1) - (count_bad(r) - count_bad(l - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << good_count(l, r) << '\n';
    }

    return 0;
}
