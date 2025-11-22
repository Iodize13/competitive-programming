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
    int cur = -1;
    int prev = a[n - 1];
    vector<int> pr;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] % a[i] != 0) {
            if (cur == -1) {
                cur = a[i];
            }
            cur = __gcd(cur, a[i]);
            pb = a[i];
            // cerr << "a[i]: " << a[i] << ' ' << a[i] % a[i - 1] << '\n';
            // pb = a[i - 1];
        }
        if (a[i + 1] % a[i] != 0 || a[i] > prev) {
            pr.push_back(i);
        } else {
            prev = a[i];
        }
    }
    cerr << "pr: ";
    for (auto X: pr) cerr << X << ' ';
    cerr << '\n';
//     if (pb == -1) {
//         cout << 69 << '\n';
//         return;
//     }

//    cerr << "pb: " << pb << '\n';
    vector<int> co;
    for (int i = 1; i * i <= cur; i++) {
        if (cur % i == 0) {
            co.push_back(i);
            co.push_back(cur / i);
        }
    }
    sort(co.begin(), co.end());
    cerr << "dbg: ";
    for (auto X: co) cerr << X << ' ';
    cerr << '\n';

    // for (int i = 1; i < n ;i++) {
    //     if (a[i] % a[i - 1] != 0) {
    //         int tmp = a[i - 1];
    //         for (auto it = co.begin(); it != co.end();) {
    //             if (tmp % *it != 0 || a[i] % (tmp / *it) != 0) {
    //                 co.erase(it++);
    //             }
    //             else {
    //                 cerr << "me: " << *it << '\n';
    //                 it++;
    //             }
    //         }
    //     }
    // }

    int hi = co.size() - 1;
    int lo = 0;
    int ans;
    while (hi >= lo) {
        int mid = (hi + lo) / 2;
        bool ok = true;
        vector<int> vt = a;
        for (auto X: pr) vt[X] /= co[mid];
        int ss = 0;
        for (auto X: pr) {
            if (X == 0) {
                if (vt[X] > vt[X + 1]) {
                    ss = 2;
                    break;
                }
            } else {
                if (X + 1 < vt.size() - 1 && vt[X] > vt[X + 1]) {
                    ss = 2;
                    break;
                } else if (X - 1 >= 0 && vt[X] < vt[X - 1]) {
                    ss = 1;
                    break;
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (vt[i + 1] % vt[i] != 0) {
                cerr << "boom: << '\n';
            }
        }
        if (ss == 0) {
            ans = co[mid];
            break;
        } else if (ss == 1) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    // cerr << "dbg: ";
    // for (auto X: co) cerr << X << '\n';
    // cerr << "size: " << co.size() << '\n';
    cout << ans << '\n';
    // cerr << __gcd(73080 ,42) << '\n';
    // cerr << 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 << '\n';
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
