#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n;
    vector<int> a(n + 2);
    int Asum = 0;
    map<int, int> mp;
    for (int i = 0; i < n + 2; i++) {
        cin >> a[i];
        Asum += a[i];
        mp[a[i]]++;
    }

    for (int i = 0; i < n + 2; i++) {
        if ((Asum - a[i]) % 2 == 0 && mp[(Asum - a[i]) / 2]) {
            // cerr << "Asum - a[i]: " << Asum - a[i] << '\n';
            if (a[i] == (Asum - a[i]) / 2) {
                if (mp[a[i]] > 1) {
                    int temp = a[i];
                    auto it = find(all(a), temp);
                    a.erase(it);
                    it = find(all(a), temp);
                    a.erase(it);
                    for (auto &X: a) cout << X << ' ';
                    cout << '\n';
                return;
                } else {
                    continue;
                }
            } 
            int temp = (Asum - a[i]) / 2;
            auto it = find(all(a), a[i]);
            a.erase(it);
            it = find(all(a), temp);
            a.erase(it);
            for (auto &X: a) cout << X << ' ';
            cout << '\n';
            return;
        }
    }

    cout << "-1\n";
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

