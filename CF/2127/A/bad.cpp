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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i < n ;i++) {
        if (a[i - 2] == -1 || a[i - 1] == -1 || a[i] == -1) {
            for (int j = 0;j 
        }
        vector<int> b(3);
        for (int j = i - 2; j <= i; j++) {
            if (a[i] < 3) b[a[i]]++;
        }
        int mex = 0;
        while(b[mex]) mex++;
        if (mex == max(a[i], max(a[i - 1], a[i - 2])) - min(a[i], min(a[i - 2], a[i - 1]))) continue;
        else {
            cout << "NO\n";
        }
    }

    cout << "YES\n";
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

