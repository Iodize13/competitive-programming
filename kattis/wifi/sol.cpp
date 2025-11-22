#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

vector<ld> a;

int numOfAdd(ld ra) {
    ld prv = a[0];
    int cnt = 0;
    while (prv <= a[n - 1]) {
        cnt++;
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = midpoint(l, r);
            // cerr << mid << '\n';
            if (a[mid] > prv + 2 * ra) {
                r = mid;
            } else {
                l = mid;
            }
        }
        // cerr << "r : " << r << "\n";
        if (r <= n - 1) prv = a[r];
        else break; //?
    }

    return cnt;
}

void sol() {
    cin >> m >> n;
    a.resize(n);
    for (int i = 0; i <n ; i++) {
        cin >> a[i];
    }

    sort(all(a));
    ld l = 0, r = 1e6;
    while(r - l > 0.01L) {
        ld mid = midpoint(l, r);
        // cerr << "numOfAdd(mid): " << numOfAdd(mid) << '\n';
        // cerr << mid << '\n';
        if (numOfAdd(mid) <= m) {
            r = mid;    
        } else {
            l = mid;
        }
    }

    cout << setprecision(1) << fixed << l << '\n';
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

