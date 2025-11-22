#include <bits/stdc++.h>
//#include <cstdio>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define eb emplace_back
using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using ld=long double;

void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

ll n, m, q, l, y ,z;
string s, t;

const char nl = '\n';
ll c[(int)1e6+ 9];

ll pyta(int num, int aa) {
    return sqrt(pow(num, 2) - pow(aa, 2));
}

void runcase(){
    cin >> n;
    vector<int> a(n);
    for (int i= 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, j = n - 1;
    vector<int> b;
    while (i < j) {
        if (a[i] > a[j]) {
            b.emplace(a[j], 0);
            j--;
        } else {
            b.emplace_back(a[i]);
            i++;
        }
    }
    for (auto X: b) {
	cerr << X << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase(1); cin>>testcase;
    while(testcase--) runcase();
    return 0;
}

