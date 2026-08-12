// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
void solve();

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int32_t main(int32_t argc, char* argv[]) {
    send help
    srand(atoi(argv[1]));

    solve();
}

void solve() {
    int n = rand(1, 10);
    string s = "";
    rep(i,0,n) {
        s += rand(0, 5) + 'a';
    }

    cout << s << '\n';
}
