#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    set<int> st;
    for (int i = 0; i < n; i++) {
        auto it = st.lower_bound(a[i]);
        if (it == st.end()) {
            st.insert(a[i]);
        } else {
            int temp = *prev(st.end());
            st.erase(it, st.end());
            st.insert(temp);
        }
    }

    cout << sz(st) << '\n';
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

