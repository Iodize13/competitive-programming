#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> s;
    int y = stoll(s);
    if ((int)(sqrt(y)) * (int)(sqrt(y)) == y) {
       cout << (int)(sqrt(y)) << ' ' << "0\n";
       return;
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

