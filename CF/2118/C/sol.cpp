#include <bits/stdc++.h>
#define int long long
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

int n, m, k, q, l, y ,z;
char c[(int)1e6+9];
string s, t;

const char nl = '\n';
void runcase(){
  cin >> n >> k;
  vector<int> b(64);
  vector<int> a(n);
  for (auto &x: a) 
    cin >> x;

  for (auto &x: a) {
    int j = 0;
    while(x) {
      b[j] += (x & 1);
      x >>= 1;
      ++j;
    }
  }

  // cerr << "dbg: ";
  // for (int i = 0; i <=37; i ++) {
  //   cerr << b[i] << " \n"[37 == i];
  // }
  int ans = 0;
  for (int i = 0LL; i < 63; i++) {
    assert(k >= 0);
    // cerr << "dbg: " << ( 1LL << i) << '\n';
    // cerr << "n - b[i]" << n - b[i] << '\n';
    // cerr << "k: " << k << '\n';
    int r = max(0LL, min(k, (1LL << i) * (n - b[i])));
    ans += b[i] + r / (1LL << i); // shouldn't + when it doesn't plus to that digit;
    // cerr << "r / : " << r / (1LL << i) << '\n';
    // cerr << "ans: " << ans << '\n';
    k -= r;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int testcase(1); cin>>testcase;
  while(testcase--) runcase();
  return 0;
}
