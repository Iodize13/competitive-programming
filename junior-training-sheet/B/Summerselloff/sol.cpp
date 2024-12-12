#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)

void runcase(){
  ll n, f;
  cin >> n >> f;
  ll a[n];
  ll b[n];
  ll res[n];
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    ans += min(a[i], b[i]);
    res[i] = min(a[i] * 2, b[i]) - min(a[i], b[i]);
  }
  sort(res, res + n, greater<ll>());
  for (int i = 0; i < f; i++) {
    ans += res[i];
  }
  cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}
