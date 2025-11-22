#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

void sol() {
    int a, b;
    cin >> a >> b;
    if (b > a) swap(b, a);
    int tmp = a;
    string A = "";
    int cnt = 0;
    while(tmp) {
        A += char((tmp & 1) + '0');
        tmp>>=1;
        cnt++;
    }
    for (int i = 0; i < (1 << (cnt +1)); i++) {
        if (a + i + b + i == ((a + i) ^ (b + i))) {
            cout << "YES\n";
            //cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
