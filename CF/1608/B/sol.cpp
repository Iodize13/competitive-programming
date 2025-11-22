#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    int a, b;
    cin >> n >> a >> b;
    if (((n - 1) / 2 < a || (n - 1) < b) || (a + b > n - 2) || abs(a - b) >= 2) {
        cout << "-1\n";
        return;
    } 

    vector<int> c(n);
    if (a > b) {
        int j = n;
        for (int i = n - 2; i >= 0 && a; i-=2, j--, a--) {
            c[i] = j;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] == 0) {
                c[i] = j;
                j--;
            }
        }
    } else if (a == b) {
        int j = n;
        a++;
        for (int i = n - 1; i >= 0 && a; i-=2, j--, a--) {
            c[i] = j;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] == 0) {
                c[i] = j;
                j--;
            }
        }
    } else {
        int j = 1;
        for (int i = n - 2; i >= 0 && b; i -= 2, j++, b--) {
            c[i] = j;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] == 0) {
                c[i] = j;
                j++;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << c[i] << ' ';
    cout << '\n';
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

