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
    for (int i = 0; i <n ;i++) {
        cin >> a[i];
    }

    set<int> st;
    int last = n;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
        while (!st.empty() && *prev(st.end()) == last) {
            cout << last << ' ';
            st.extract(last);
            last--;
        }
        cout << '\n';
    }
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

