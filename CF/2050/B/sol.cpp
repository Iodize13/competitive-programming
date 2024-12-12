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
    long double odd = 0;
    long double even = 0;
    int codd =0;
    int ceven = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if ((i & 1)) {
            even +=a[i];
            ceven++;
        } else {
            odd += a[i];
            codd++;
        }
    }
    // cout << "even" << even << "ceven " << ceven << '\n';
    // cout << "odd" << odd << "codd " << codd << '\n';
    if ((even / ceven) - int(even / ceven) > 0.00000000001 ||
            (odd / codd) - int(odd / codd) > 0.00000000001) {
        cout << "NO\n";
        return;
    }
    cout << (int(even/ceven) == int(odd/codd) ? "YES" : "NO") << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



