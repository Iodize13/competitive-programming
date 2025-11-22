#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    vector<int> b(n);
    for (auto &x: b)
        cin >> x;

    int h = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            if (h == -1) h = a[i] + b[i];
            else {
                if (a[i] + b[i] != h) {
                    cout << "0\n";
                    return;
                }
            }
        }
    }

    if (h != -1) {
        //cerr << "h: " << h << '\n';
        for (int i = 0; i <n ; i++) {
            if (b[i] == -1) {
                if (!(h - a[i] >= 0 && h - a[i] <= k)) {
                    //cerr << "a[i]: " << a[i] << '\n';
                    cout << "0\n";
                    //cerr <<"base1\n";
                    return;
                }
            }
        }
        cout << "1\n";
    } else {
        cout << (k + *min_element(all(a))) - *max_element(all(a)) + 1 << '\n';
    }

}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

