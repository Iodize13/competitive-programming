#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    vector<string> a(3);
    cin >> a[0] >> a[1] >> a[2];
    vector<int> b(3);
    for (int i = 0; i < 3; i++) {
        if (a[i][1] == '>') b[a[i][0] - 'A']++;
        else b[a[i][2] - 'A']++;
    }
    string ans = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[j] == i) {
                ans += char(j + 'A');
                break;
            }
        }
    }
    set<char> temp(all(ans));
    if (sz(temp) != 3) {
        cout << "Impossible\n";
        return;
    }

    cout << ans <<'\n';
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

