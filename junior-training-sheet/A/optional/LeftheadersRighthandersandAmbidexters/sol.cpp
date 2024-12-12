#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    int l, r, a;
    cin >> l >> r >> a;
    int k = min(abs(l - r), a);
    a -= k;
    int ans = 2 * min(min(l, r) + k, max(r, l));
    if (a&1) a--;
    ans += a;
    cout << ans << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



