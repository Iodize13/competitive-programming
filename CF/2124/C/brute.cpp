#include<bits/stdc++.h>
#define int long long int

using namespace std;

void runcase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
        

    // int cur = a[0];
    // for (int i = 1; i < n; i++) {
    //     cur = __gcd(cur, a[i]);
    // }
    // 
    // for (int i = 0; i < n; i++) a[i] /= cur;

    int pb = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] % a[i - 1] != 0) {
            cerr << "a[i]: " << a[i] << ' ' << a[i] % a[i - 1] << '\n';
            pb = a[i - 1];
            break;
        }
    }
    if (pb == -1) {
        cout << 69 << '\n';
        return;
    }

    cerr << "pb: " << pb << '\n';
    set<int> co;
    for (int i = 1; i * i <= pb; i++) {
        if (pb % i == 0) {
            co.insert(i);
            co.insert(pb / i);
        }
    }
    cerr << "dbg: ";
    for (auto X: co) cerr << X << ' ';
    cerr << '\n';

    for (int i = 1; i < n ;i++) {
        if (a[i] % a[i - 1] != 0) {
            int tmp = a[i - 1];
            for (auto it = co.begin(); it != co.end();) {
                if (tmp % *it != 0 || a[i] % (tmp / *it) != 0) {
                    co.erase(it++);
                }
                else it++;
            }
            while (tmp) {
            }
        }
    }
    // cerr << "dbg: ";
    // for (auto X: co) cerr << X << '\n';
    cerr << "size: " << co.size() << '\n';
    cout << *co.begin() << '\n';
    // if (cur == 1)
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        runcase();
    }
	return 0;
}
