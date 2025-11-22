#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

void sol() {
    int a, b;
    cin >> a >> b;
    if (b > a) swap(b, a);
    int tmp = a;
    string A = "";
    while(tmp) {
        A += char((tmp & 1) + '0');
        tmp>>=1;
    }
    int tmpB = b;
    string B = "";
    while(tmpB) {
        B += char((tmpB & 1) + '0');
        tmpB>>=1;
    }
    int szB = sz(B);
    for (int i = 0; i < sz(A) - szB; i++) {
        B += " ";
    }
    int ans = 0;
    bool st = false;
    int c = 0, d = 0;
    for (int i = 0; i < sz(A); i++) {
        c += ((1 & (A[i] - '0')) << i);
        d += ((1 & (B[i] - '0')) << i);
        if (A[i] == '1' && B[i] == '1') {
            st = true;
        }
        if (c + ans + d + ans == ((c + ans) ^ (d + ans))) {
            cerr << "test\n";
        }
        else if (st) ans += (1 << i);
        if (st && A[i] != B[i]) {
            st = false;
        }
    }
    int e = 0, f = 0;
    int ans2 = 0;
    for (int i = sz(A); i >= 0; i--) {
        e += ((1 & (A[i] - '0')) << i);
        f += ((1 & (B[i] - '0')) << i);
        if (A[i] == '1' && B[i] == '1') {
            st = true;
            continue;
        }
        if (e + ans2 + f + ans2 == ((e + ans2) ^ (f + ans2))) {
            cerr << "test\n";
        }
        else if (st) ans2 += (1 << i);
        if (st && A[i] != B[i]) {
            st = false;
        }
    }
    // reverse(all(ans));
    // reverse(all(ansB));
    cerr << ans << '\n';
    // cerr << ansB << '\n';
    if (a + ans + b + ans == ((a + ans) ^ (b + ans))) {
        cout << "YES\n";
        // cout << ans << '\n';
    } else if (a + ans2 + b + ans2 == ((a + ans2) ^ (b + ans2))){
        cout << "YES\n";
       // cout << ans2 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
