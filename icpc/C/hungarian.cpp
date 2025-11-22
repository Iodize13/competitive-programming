#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    const int INF = (int)1e18;
    cin >> n >> m;
    vector<vector<int> > A(n + 1, vector<int>(m + 1));
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            b.push_back(A[i][j]);
        }
    }
    auto last = unique(all(b));
    b.erase(last, b.end());
    
    auto check = [&](int h, bool ans) {
        vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
        for (int i=1; i<=n; ++i) {
            p[0] = i;
            int j0 = 0;
            vector<int> minv (m+1, INF);
            vector<bool> used (m+1, false);
            do {
                used[j0] = true;
                int i0 = p[j0],  delta = INF,  j1;
                for (int j=1; j<=m; ++j)
                    if (!used[j]) {
                        int cur = -(A[i0][j] >= h) -u[i0]-v[j];
                        if (cur < minv[j])
                            minv[j] = cur,  way[j] = j0;
                        if (minv[j] < delta)
                            delta = minv[j],  j1 = j;
                    }
                for (int j=0; j<=m; ++j)
                    if (used[j])
                        u[p[j]] += delta,  v[j] -= delta;
                    else
                        minv[j] -= delta;
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }

        if (ans) {
            cout << h << '\n';
            vector<int> c(n + 1);
            for (int j=1; j<=m; ++j) c[p[j]] = j;

            for (int i = 1; i < n + 1; i++) cout << c[i] << " \n"[i==n];
        }

        return (-v[0] <= -n);
    };


    sort(all(b));
    int hi = sz(b), lo = 0;
    while (hi - lo > 1) {
        int mid = midpoint(lo, hi);
        if (check(b[mid], 0)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    check(b[lo], 1);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}
