#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    ll x = 1000, m = 100000000;
    int cnt = 0;
    for (ll i = 1; i <= m; i++) {
        if ((x ^ i) != 0 && (x % (x ^ i) == 0 || i % (x ^ i) == 0)) cnt++;
    }
    cout << cnt << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



