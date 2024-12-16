
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)

void runcase(){
  ll k, l1, r1, l2, r2;
  cin >> k >> l1 >> r1 >> l2 >> r2;
  ll ans = 0;
  for (ll i = 1; i <= r2/l1; i *= k) {
    // what if it not devidable
    ll r = min(r2 / i, r1);
    ll l = max((ll)ceil(double(l2) / i), l1);
    if (r >= l) ans += r - l + 1;
  }
  cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}
