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
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
const int inf = (int)2e18 + 5;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int32_t main(int32_t argc, char* argv[]) {
    send help
    srand(atoi(argv[1]));
    solve();
}

void solve() {
	// int N = rand(1, 100);
	int N = 5000;
	for (int i = 0; i < N; i++) cout << char('a' + rand(0, 25));
	cout << '\n';
}

