#include<bits/stdc++.h>
#define int long long

using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    memset(a, 0, sizeof a);
    map<int, multiset<int>> mp;
    for (int i = 0; i < n; i++) {
        int H;
        cin >> H;
        if (H < n && a[H]) mp[H % m].insert(H);
        if (H < n) a[H] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            int M = (i) % m;
            if (mp[M].empty()) break;
            auto cur = *mp[M].begin();
            mp[M].erase(mp[M].begin());
            if (cur > i) break;
            a[i] = 1;
        }
    }

    int mex = 0;
    while(a[mex]) mex++;
    cout << mex << '\n';
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
