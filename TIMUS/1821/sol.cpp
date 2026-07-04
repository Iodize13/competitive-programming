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

int32_t main() {
    send help

    solve();
}

struct Runner {
    int time, en_time;
    string name;
    Runner(int r_time, int r_en_time, string r_name) {
	time = r_time;
	en_time = r_en_time;
	name = r_name;
    }
    bool operator<(const Runner& other) const {
	return time < other.time;
    }
};

void solve() {
    int N; cin >> N;
    vector<Runner> A;
    vector<string> ans;
    for (int i = 0; i < N; i++) {
	string s, f; cin >> s >> f;
	int d_minute = f.find(":");
	int time = stoll(f.substr(0, d_minute)) * 60 * 10;
	int d_sec = f.find(".");
	int sec = stoll(f.substr(d_minute + 1, d_sec - d_minute -1 )) * 10;
	time += sec;
	int mili = stoll(f.substr(d_sec + 1));
	time += mili;

	Runner tmp(time, time + i * 30 * 10, s);
	A.push_back(tmp);
    }

    multiset<Runner> MS;
    sort(all(A), [](const Runner& a,const Runner& b) {
	    return a.en_time < b.en_time;
	    });
    for (int i = 0; i < N; i++) {
	MS.insert(A[i]);
	if (MS.begin()->name == A[i].name) {
	    ans.push_back(A[i].name);
	}
    }
    cout << sz(ans) << '\n';
    sort(ans.begin(), ans.end());
    for (auto &x: ans) {
	cout << x << '\n';
    }
}

