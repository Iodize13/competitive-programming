#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 0;
    int mxE = a[n-1];
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != mxE) {
            if (cnt & 1) {
                cout << "YES\n";
                return;
            }
            mxE = a[i];
            cnt = 0;
        }
     //   cout << "mxE: " << mxE << ", ";
        if (a[i] == mxE) cnt++;
      //  cout << "cnt: " << cnt << '\n';
    }
    if (cnt & 1) {
       // cout << cnt << ' ';
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}

// 3m13.220s
// 30m13
