#include <bits/stdc++.h>
using namespace std;

bool isDifficult(const string &s) {
    for (int i = 0; i + 2 < s.size(); ++i) {
        string sub = s.substr(i, 3);
        if (sub == "FFT" || sub == "NTT") {
            return true;
        }
    }
    return false;
}

string solve(string s) {
    if (!isDifficult(s)) {
        return s;
    }
    int t_count = 0;
    string others;
    for (char c : s) {
        if (c == 'T') {
            t_count++;
        } else {
            others.push_back(c);
        }
    }
    string result;
    result.append(t_count, 'T');
    result += others;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string res = solve(s);
        cout << res << '\n';
    }
    return 0;
}