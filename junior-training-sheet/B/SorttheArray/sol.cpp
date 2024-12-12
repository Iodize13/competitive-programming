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
  int a[n + 1];
  a[n] = int(1e9) + 9;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = 0;
  int st = -1, en = 0;
  int mxBefore = -1;
  bool valid = 1;
  for (int i = 0; i < n; i++) {
    // decreasing
    if (a[i] > a[i + 1]) {
      if (st != -1) {
        if (en != 0) {
          valid = 0;
          break;
        }
      } else {
          mx = a[i];
          st = i + 1;
      }
      // increasing
    } else {
      if (st == -1) {
        mxBefore = max(mxBefore, a[i]);
      } else {
        if (a[i] < mxBefore) {
          valid = 0;
          break;
        }
        if (en != 0) {
          continue;
        } else {
          if (a[i + 1] < mx) {
            valid = 0;
            break;
          } else {
            en = i + 1;
          }
        }
      }
    }
    // if (mx && a[i] < a[i + 1] && !en) en = i + 1;
  }
  if (!valid) {
    cout << "no\n";
    return;
  }
  // cout << mxBefore << '\n';
  if (st != -1) {
    cout << "yes\n" << st << ' ' << en << '\n';
    return;
  }
  cout << "yes\n1 1\n";
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}
