#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)

void runcase(){
  ll m;
  cin >> m;
  ll a, b, c;
  cin >> a >> b >> c;
  ll ans = 0;
  ans +=min(m, a) + min(m,b);
  ll k = min (m- min(m, a), c);
  ans +=k;
  c-= k;
  k=min(m- min(m,b), c);
  ans += k;
  c-= k;
  cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}
