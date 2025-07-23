#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll a, b, k;
        cin >> a >> b >> k;

        ll need = max((a + k - 1) / k, (b + k - 1) / k);

        ll g = gcd(a, b);

        if (g >= need) {
            cout << 1 << '\n'; 
        } 
        else {
            cout << 2 << '\n'; 
        }
    }

    return 0;
}
