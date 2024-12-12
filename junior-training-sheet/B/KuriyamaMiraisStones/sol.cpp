#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)
             
void runcase(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll pa[n + 1]{0};
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i - 1];
        pa[i] = sum;
    }
    /*cout << "sum" << sum << '\n';*/
    sort(a, a + n);
    ll ps[n + 1]{0};
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i - 1];
        ps[i] = sum;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, ty;
        cin >> ty >> l >> r;
        // --l;
        // --r;
        if (ty == 1) {
            /*cout << pa[r] << '\n';*/
            /*cout << pa[l] << '\n';*/
            cout << pa[r] - pa[l - 1] << '\n'; 
        } else {
            /*cout << ps[r] << '\n';*/
            /*cout << ps[l] << '\n';*/
            cout << ps[r] - ps[l - 1] << '\n';
        }
    }
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



