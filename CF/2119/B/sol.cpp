#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int tt = 1;

void runcase() {
    ll n;
    cin >> n;
    ll sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    vector<ll> q(n);
    long double sum = 0;
    for (int i =0 ; i < n; i++) {
        cin >> q[i];
        sum += q[i];
    }
    // if (tt == 4389) {
    //     string t = "";
    //     t +=  to_string(n) + ":" + to_string(sx) + ":" + to_string(sy) + ":" + to_string(ex) + ":" + to_string(ey) + ":";
    //     for (int i = 0; i < n; i++) {
    //         t += to_string(q[i]) + ",";
    //     }
    //     t+= "\n";
    //     cout << t;
    //     return;
    // }
    ll disx = abs(ey - sy);
    ll disy = abs(sx - ex);
    // if (sum * sum == disx*disx + disy*disy) {
    //     cout << "YES\n";
    //     return;
    // }
    if (disx*disx + disy*disy == 0) {
        if (n == 1) {
            cout << "NO\n";
            return;
        }
        if (n == 2) {
            if (q[0] == q[1]) {
            cout << "YES\n";
            } else {
            cout << "NO\n";
            }
            return;
        }
        if (n >= 3) {
            ll a = 0;
            ll c = 0;
            bool ok = false;
            for (int i = 0 ; i < n; i++) {
                a += q[i];
                ll b = 0;
                for (int j = n -1; j > i; j--) {
                    b += q[j];
                    c = sum - (a + b);
                    if (a + b >= c && a + c >= b && c + b >= a) ok = true;
                }
            }
            cout << (ok ?  "YES": "NO") << '\n';
            return;
        }
    }
    if (sum * sum < disx*disx + disy*disy) {
        cout << "NO\n";
    } else {
            long double a = sqrt(disx*disx + disy*disy);
            long double c = 0;
            bool ok = false;
            for (int i = 0 ; i < n; i++) {
                a += q[i];
                long double b = 0;
                for (int j = n -1; j > i; j--) {
                    b += q[j];
                    c = sum - (a + b - sqrt(disx*disx + disy*disy));
                    if (a + b >= c && a + c >= b && c + b >= a) ok = true;
                }
            }
            a = 0;
            c = sqrt(disx*disx + disy*disy);
            for (int i = 0 ; i < n; i++) {
                a += q[i];
                long double b = sum - a;
                if (a + b >= c && a + c >= b && c + b >= a) ok = true;
            }
            cout << (ok ?  "YES": "NO") << '\n';
            return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase(1); cin >> testcase;
    while(testcase--) {
        runcase();
        tt++;
    }
    return 0;
}
